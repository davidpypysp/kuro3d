#include "src/gui/imgui/app.h"

namespace kuro {

namespace gui {

App::App() { context_ = std::make_shared<Context>(); }

void App::Run() {}

}  // namespace gui

}  // namespace kuro
