// dear imgui: standalone example application for GLFW + OpenGL 3, using
// programmable pipeline If you are new to dear imgui, see examples/README.txt
// and documentation at the top of imgui.cpp. (GLFW is a cross-platform general
// purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics
// context creation, etc.)

#include <iostream>

#include "src/gui/imgui/gui_main.h"

int main(int, char **) {
  kuro::gui::GuiMain::Instance()->Run();
  return 0;
}
