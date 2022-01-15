#include "src/gui/imgui/app.h"
#include "iostream"

namespace kuro {

namespace gui {

App::App() { context_ = std::make_shared<Context>(); }

void App::Run() { std::cout << "try running" << std::endl; }

}  // namespace gui

}  // namespace kuro
