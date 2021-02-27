#ifndef SRC_GUI_IMGUI_SCENE_VIEWER_H_
#define SRC_GUI_IMGUI_SCENE_VIEWER_H_

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace kuro {
namespace gui {

class SceneViewer {
  SceneViewer();

  void Render();
};

}  // namespace gui
}  // namespace kuro

#endif  // SRC_GUI_IMGUI_SCENE_VIEWER_H_
