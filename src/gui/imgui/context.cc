#include "src/gui/imgui/context.h"
#include "src/core/engine.h"
#include "src/gui/imgui/gui_manager.h"
#include "src/gui/imgui/gui_system.h"
#include "src/gui/imgui/gui_store.h"

namespace kuro {

namespace gui {

Context::Context() {
  auto engine = Register<Engine>();

  auto gui_store = Register<GuiStore>();

  auto gui_manager = Register<GuiManager>();
  gui_manager->RegisterEngine(engine);
  gui_manager->RegisterGuiStore(gui_store);

  auto gui_system = Register<GuiSystem>();
  gui_system->RegisterEngine(engine);
  gui_system->RegisterGuiManager(gui_manager);
}

}  // namespace gui

}  // namespace kuro