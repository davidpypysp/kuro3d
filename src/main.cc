#include <iostream>

#include "src/gui/imgui/gui_main.h"

int main(int, char **) {
  kuro::gui::GuiMain::Instance()->Run();
  return 0;
}
