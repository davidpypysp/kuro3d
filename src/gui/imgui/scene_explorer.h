#ifndef SRC_GUI_IMGUI_SCENE_EXPLORER_H_
#define SRC_GUI_IMGUI_SCENE_EXPLORER_H_

#include <string>
#include "src/gui/imgui/window.h"

namespace kuro {
namespace gui {

class SceneExplorer : public Window {
 public:
  explicit SceneExplorer(const std::string &name);

  void Render();
};

}  // namespace gui
}  // namespace kuro

#endif  // SRC_GUI_IMGUI_SCENE_EXPLORER_H_
