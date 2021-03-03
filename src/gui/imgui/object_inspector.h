#ifndef SRC_GUI_IMGUI_OBJECT_INSPECTOR_H_
#define SRC_GUI_IMGUI_OBJECT_INSPECTOR_H_

#include "src/gui/imgui/window.h"

namespace kuro {

namespace gui {

class ObjectInspector : public Window {
 public:
  explicit ObjectInspector(const std::string &name);

  void Render();

 protected:
};

}  // namespace gui

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_OBJECT_INSPECTOR_H_
