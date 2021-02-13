#include "src/gui/imgui/gui_main.h"
#include "src/gui/imgui/gui.h"
#include "src/core/renderer/renderer.h"

#include <stdio.h>
// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to
// maximize ease of testing and compatibility with old VS compilers. To link
// with VS2010-era libraries, VS2015+ requires linking with
// legacy_stdio_definitions.lib, which we do using this pragma. Your own project
// should not be affected, as you are likely to link with a newer binary of GLFW
// that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && \
    !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

namespace kuro {

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int gui_main() {
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) return 1;

  Gui gui;
  gui.Init();

  Renderer renderer;
  renderer.Init();

  // Main loop
  while (!glfwWindowShouldClose(gui.window())) {
    glfwPollEvents();
    gui.PrepareDraw();

    renderer.Draw();
    gui.Draw();

    glfwSwapBuffers(gui.window());
  }

  // Cleanup
  renderer.Cleanup();
  gui.Cleanup();

  glfwTerminate();
  return 0;
}
}  // namespace kuro
