#include "src/core/engine.h"
#include "src/core/default_scenario.h"

namespace kuro {

Engine::Engine() { context_ = std::make_shared<Context>(); }

Engine::~Engine() {}

void Engine::Init() { LoadScenario(); }

void Engine::LoadScenario() { CreateDefaultScene(context_); }

}  // namespace kuro
