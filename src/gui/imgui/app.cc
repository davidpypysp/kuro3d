#include "src/gui/imgui/app.h"

#include "iostream"

#include "src/gui/imgui/gui_system.h"

namespace kuro {

namespace gui {

App::App() { context_ = std::make_shared<Context>(); }

void App::Run() {
  std::cout << "try running" << std::endl;
  auto gui_system = context_->Resolve<GuiSystem>();
  gui_system->Run();
}

}  // namespace gui

}  // namespace kuro
