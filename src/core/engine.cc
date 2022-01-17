#include "src/core/engine.h"

#include "src/core/default_scenario.h"

namespace kuro {
namespace core {

Engine::Engine() {
  context_ = std::make_shared<Context>();
  renderer_ = context_->Resolve<Renderer>();
}

Engine::~Engine() {}

void Engine::LoadScenario() { CreateDefaultScene(context_); }

void Engine::Init() {
  renderer_->Init();
  LoadScenario();
}

void Engine::Draw() { renderer_->RenderScene(); }

}  // namespace core
}  //  namespace kuro
