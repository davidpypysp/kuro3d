#include <iostream>

#include "src/gui/imgui/gui_system.h"

int main(int, char **) {
  kuro::gui::GuiSystem gui_system;
  gui_system.Run();
  return 0;
}
