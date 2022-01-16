#ifndef CORE_RENDERER_RENDERING_PIPELINE_H_
#define CORE_RENDERER_RENDERING_PIPELINE_H_

#include <memory>

#include "src/utils/dependency_helper.h"
#include "src/core/base/mesh_comp.h"
#include "src/core/scene/scene_node.h"
#include "src/core/renderer/shader_manager.h"
#include "src/core/renderer/render_api.h"

namespace kuro {

class RenderingPipeline {
 public:
  RenderingPipeline();

  void Setup();

  // Render one frame by gpu (given all mesh, light...)
  void DrawFrame(std::shared_ptr<SceneNode> root_node,
                 std::shared_ptr<SceneNode> camera_node);

  // dependencies
  REGISTER_DEPENDENCY(RenderAPI, render_api_)
  REGISTER_DEPENDENCY(ShaderManager, shader_manager_)

 protected:
  void PrepareDraw(std::shared_ptr<SceneNode> camera_node);

  void DrawMesh(MeshData& mesh_data);

  // Render one mesh with material's shader program and geometry data
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node);

  // data
  std::vector<MeshData> mesh_data_list_;
};

REGISTER_TYPE_ANNOTATION(RenderingPipeline)

}  // namespace kuro

#endif