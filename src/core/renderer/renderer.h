#ifndef SRC_CORE_RENDERER_RENDERER_H_
#define SRC_CORE_RENDERER_RENDERER_H_

#include <memory>
#include "src/core/renderer/shader.h"
#include "src/core/elements/model_pack.h"
#include "src/core/elements/camera_pack.h"
#include "src/core/scene/scene_manager.h"

namespace kuro {

class Renderer {
 public:
  Renderer(const unsigned int width, const unsigned int height);
  void Init();
  void Draw();
  void Cleanup();

 private:
  unsigned int width_;
  unsigned int height_;

  std::shared_ptr<Shader> shader_;
  std::shared_ptr<SceneManager> scene_manager_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_RENDERER_H_
