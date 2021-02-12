#ifndef KURO_GUI_IMGUI_GUI_H_
#define KURO_GUI_IMGUI_GUI_H_

#include <glad/glad.h>  // Initialize with gladLoadGL()
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace kuro {

int gui_main();

}  // namespace kuro

#endif  // KURO_GUI_IMGUI_GUI_H_