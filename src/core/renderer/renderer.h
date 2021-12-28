#ifndef CORE_RENDERER_RENDERER_H_
#define CORE_RENDERER_RENDERER_H_

#include <memory>
#include "src/core/base/shader.h"
#include "src/core/scene/scene_node.h"

namespace kuro {

class Renderer {
 public:
  Renderer();
  ~Renderer();
  void Init();
  void DrawScene();

  std::shared_ptr<Shader> shader() { return shader_; }

 private:
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node);

  std::shared_ptr<Shader> shader_;
};

}  // namespace kuro

#endif  // CORE_RENDERER_RENDERER_H_
