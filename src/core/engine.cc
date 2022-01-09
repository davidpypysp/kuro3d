#include "src/core/engine.h"
#include "src/core/renderer/gl_render_api.h"

namespace kuro {

Engine* Engine::instance_ = nullptr;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::Init() { instance_ = new Engine(); }

Engine* Engine::Instance() { return instance_; }

void Engine::SetWindowSize(const unsigned int width,
                           const unsigned int height) {
  window_height_ = height;
  window_width_ = width;
}

}  // namespace kuro
