#ifndef GUI_IMGUI_GUI_BASE_H_
#define GUI_IMGUI_GUI_BASE_H_

#include <string>
#include <memory>
#include <vector>

#include "src/gui/imgui/window.h"

namespace kuro {

namespace gui {

class GuiBase {
 public:
  GuiBase();

  ~GuiBase();

  void Draw();

 protected:
  template <class T>
  std::shared_ptr<T> AddWindow(const std::string& name) {
    std::shared_ptr<Window> window = std::make_shared<T>(name);
    windows_.push_back(window);
    return std::static_pointer_cast<T>(window);
  }

  std::vector<std::shared_ptr<Window>> windows_;
};

}  // namespace gui

}  // namespace kuro

#endif  // GUI_IMGUI_GUI_BASE_H_
