#ifndef CORE_RENDERER_RENDERING_PIPELINE_H_
#define CORE_RENDERER_RENDERING_PIPELINE_H_

#include <memory>

#include "src/core/base/mesh_data.h"
#include "src/core/scene/scene_node.h"
#include "src/core/renderer/shader_manager.h"
#include "src/core/renderer/render_api.h"

namespace kuro {

class RenderingPipeline {
 public:
  void PrepareDraw();

  // Render one mesh with material's shader program and geometry data
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node);

  // Render one frame by gpu (given all mesh, light...)
  void DrawFrame(std::shared_ptr<SceneNode> root_node);

 protected:
  // dependencies
  std::shared_ptr<RenderAPI> render_api_;
  std::shared_ptr<SceneNode> camera_node_;
  std::shared_ptr<ShaderManager> shader_manager_;

  // data
  std::vector<MeshData> mesh_data_list_;
};

}  // namespace kuro

#endif