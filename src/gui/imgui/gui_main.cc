#include "src/gui/imgui/gui_main.h"

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

static void framebuffer_size_callback(GLFWwindow *window, int width,
                                      int height) {
  std::cout << "framebuffer size = "
            << "width=" << width << "height=" << height << std::endl;
  glViewport(0, 0, width, height);
}

GuiMain::GuiMain() {}

int GuiMain::Run() {
  const unsigned int window_width = 3600, window_height = 1800;

  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) return 1;

    // Decide GL+GLSL versions
#if __APPLE__
  // GL 3.2 + GLSL 150
  const char *glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // Required on Mac
#else
  const char *glsl_version = "#version 330";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(
      GLFW_OPENGL_PROFILE,
      GLFW_OPENGL_CORE_PROFILE);  // 3.2+
                                  // only
                                  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                                  // GL_TRUE); // 3.0+ only
#endif

  // Create window with graphics context
  window_ = glfwCreateWindow(window_width, window_height, "kuro3d", NULL, NULL);
  if (window_ == NULL) {
    return 1;
  }
  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1);  // Enable vsync
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

  // Initialize OpenGL loader
  bool err = gladLoadGL() == 0;

  //     glbinding::initialize([](const char *name) { return
  //     (glbinding::ProcAddress)glfwGetProcAddress(name); });
  if (err) {
    fprintf(stderr, "Failed to initialize OpenGL loader!\n");
    return 1;
  }

  gui_ = std::make_unique<Gui>(window_, glsl_version);
  renderer_ = std::make_shared<Renderer>(window_width, window_height);

  Init();

  // Main loop
  while (!glfwWindowShouldClose(window_)) {
    glfwPollEvents();
    int display_w, display_h;
    glfwGetFramebufferSize(window_, &display_w, &display_h);

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Loop();

    glfwSwapBuffers(window_);
  }

  Cleanup();

  glfwTerminate();
  return 0;
}

void GuiMain::Init() {
  std::cout << "init" << std::endl;
  renderer_->Init();
  std::cout << "ready" << std::endl;
}

void GuiMain::Loop() {
  renderer_->Draw();
  gui_->Draw();
}

void GuiMain::Cleanup() {
  // Cleanup
  renderer_->Cleanup();
  gui_->Cleanup();
}

}  // namespace kuro
