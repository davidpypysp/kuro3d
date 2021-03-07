#ifndef SRC_CORE_ENGINE_H_
#define SRC_CORE_ENGINE_H_

#include <memory>

#include "src/core/renderer/renderer.h"
#include "src/core/renderer/render_api.h"
#include "src/core/scene/scene_manager.h"
#include "src/core/renderer/texture_loader.h"
#include "src/core/renderer/model_loader.h"

namespace kuro {

class Engine {
 public:
  Engine();
  ~Engine();

  static void Init();
  static Engine* Instance();
  static std::shared_ptr<RenderAPI> GetRenderAPI();
  static std::shared_ptr<TextureLoader> GetTextureLoader();
  static std::shared_ptr<ModelLoader> GetModelLoader();

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
  std::shared_ptr<RenderAPI> render_api_;
  std::shared_ptr<SceneManager> scene_manager_;
  std::shared_ptr<TextureLoader> texture_loader_;
  std::shared_ptr<ModelLoader> model_loader_;
};

}  // namespace kuro

#endif  // SRC_CORE_ENGINE_H_
