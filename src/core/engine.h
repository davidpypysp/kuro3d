#ifndef SRC_CORE_ENGINE_H_
#define SRC_CORE_ENGINE_H_

#include <memory>

#include "src/core/renderer/renderer.h"
#include "src/core/scene/scene_manager.h"

namespace kuro {

class Engine {
 public:
  Engine();
  ~Engine();

  static void Init();
  static Engine* Instance();

  std::shared_ptr<SceneManager> scene_manager() { return scene_manager_; }
  std::shared_ptr<Renderer> renderer() { return renderer_; }

  void SetWindowSize(const unsigned int width, const unsigned int height);
  unsigned int window_width() const { return window_width_; }
  unsigned int window_height() const { return window_height_; }

  void Draw();

 protected:
  static Engine* instance_;
  unsigned int window_width_;
  unsigned int window_height_;
  std::shared_ptr<Renderer> renderer_;
  std::shared_ptr<SceneManager> scene_manager_;
};

}  // namespace kuro

#endif  // SRC_CORE_ENGINE_H_
