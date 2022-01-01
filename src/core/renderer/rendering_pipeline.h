#ifndef CORE_RENDERER_RENDERING_PIPELINE_H_
#define CORE_RENDERER_RENDERING_PIPELINE_H_

#include <memory>

#include "src/core/base/dependency_helper.h"
#include "src/core/base/mesh_comp.h"
#include "src/core/scene/scene_node.h"
#include "src/core/renderer/shader_manager.h"
#include "src/core/renderer/render_api.h"

namespace kuro {

class RenderingPipeline {
 public:
  RenderingPipeline();

  void Setup();

  void PrepareDraw();

  void DrawMesh(MeshData& mesh_data);

  // Render one mesh with material's shader program and geometry data
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node);

  // Render one frame by gpu (given all mesh, light...)
  void DrawFrame(std::shared_ptr<SceneNode> root_node);

  // dependencies
  REGISTER_DEPENDENCY(RenderAPI, render_api_)
  REGISTER_DEPENDENCY(ShaderManager, shader_manager_)

 protected:
  // data
  std::vector<MeshData> mesh_data_list_;
  std::shared_ptr<SceneNode> camera_node_;

  // TODO: remove temp
  std::shared_ptr<ShaderHandle> temp_shader_handle_;
};

}  // namespace kuro

#endif