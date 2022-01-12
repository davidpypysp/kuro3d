#include "src/gui/imgui/context.h"
#include "src/core/engine.h"
#include "src/gui/imgui/gui_manager.h"
#include "src/gui/imgui/gui_system.h"
#include "src/gui/imgui/gui_store.h"

namespace kuro {

namespace gui {

Context::Context() {
  Register<Engine>();
  Register<GuiSystem>();
  Register<GuiManager>();
  Register<GuiStore>();
}

}  // namespace gui

}  // namespace kuro