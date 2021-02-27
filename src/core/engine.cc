#include "src/core/engine.h"

namespace kuro {

Engine* Engine::instance_ = nullptr;

Engine::Engine() {
  renderer_ = std::make_shared<Renderer>();
  scene_manager_ = std::make_shared<SceneManager>();
}

Engine::~Engine() {}

void Engine::Init() {
  instance_ = new Engine();
  instance_->renderer_->Init();
  instance_->scene_manager_->CreateDefaultScene();
}

Engine* Engine::Instance() { return instance_; }

void Engine::SetWindowSize(const unsigned int width,
                           const unsigned int height) {
  window_height_ = height;
  window_width_ = width;
}

void Engine::Draw() { scene_manager_->Draw(renderer_->shader()); }

void Engine::Cleanup() { renderer_->Cleanup(); }

}  // namespace kuro
