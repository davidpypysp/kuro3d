#include "src/core/engine.h"
#include "src/core/renderer/gl_render_api.h"

namespace kuro {

Engine* Engine::instance_ = nullptr;

Engine::Engine() {
  render_api_ = std::make_shared<GLRenderAPI>();
  renderer_ = std::make_shared<Renderer>();
  scene_manager_ = std::make_shared<SceneManager>();
  texture_loader_ = std::make_shared<TextureLoader>();
  model_loader_ = std::make_shared<ModelLoader>();
}

Engine::~Engine() {}

void Engine::Init() {
  instance_ = new Engine();
  instance_->render_api_->Init();
  instance_->renderer_->Init();
  instance_->scene_manager_->CreateDefaultScene();
}

Engine* Engine::Instance() { return instance_; }

std::shared_ptr<SceneManager> Engine::GetSceneManager() {
  return instance_->scene_manager_;
}

std::shared_ptr<Renderer> Engine::GetRenderer() { return instance_->renderer_; }

std::shared_ptr<RenderAPI> Engine::GetRenderAPI() {
  return instance_->render_api_;
}

std::shared_ptr<TextureLoader> Engine::GetTextureLoader() {
  return instance_->texture_loader_;
}

std::shared_ptr<ModelLoader> Engine::GetModelLoader() {
  return instance_->model_loader_;
}

void Engine::SetWindowSize(const unsigned int width,
                           const unsigned int height) {
  window_height_ = height;
  window_width_ = width;
}

void Engine::Draw() { renderer_->DrawScene(); }

}  // namespace kuro
