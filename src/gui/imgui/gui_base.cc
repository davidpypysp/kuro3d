#include "src/gui/imgui/gui_base.h"

namespace kuro {

namespace gui {

GuiBase::GuiBase() {}

void GuiBase::Draw() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // 1. Show the big demo window (Most of the sample code is in
  // ImGui::ShowDemoWindow()! You can browse its code to learn more about
  // Dear ImGui!).
  bool show_demo_window = true;
  ImGui::ShowDemoWindow(&show_demo_window);

  for (auto window : windows_) {
    window->RenderFrame();
  }

  // Rendering
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

GuiBase::~GuiBase() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

}  // namespace gui

}  // namespace kuro
