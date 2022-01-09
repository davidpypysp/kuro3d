#ifndef GUI_IMGUI_GUI_MANAGER_H_
#define GUI_IMGUI_GUI_MANAGER_H_

#include <string>
#include <memory>

#include "src/utils/type_annotation.h"
#include "src/utils/dependency_helper.h"
#include "src/gui/imgui/gui_base.h"
#include "src/gui/imgui/gui_store.h"
#include "src/gui/imgui/scene_explorer.h"
#include "src/gui/imgui/object_inspector.h"

namespace kuro {

namespace gui {

class GuiManager : public GuiBase {
 public:
  GuiManager();

  void Init();

  REGISTER_DEPENDENCY(GuiStore, gui_store_)

 protected:
  void InitWindows();

  std::shared_ptr<SceneExplorer> scene_explorer_;
  std::shared_ptr<ObjectInspector> object_inspector_;
};

}  // namespace gui

REGISTER_TYPE_ANNOTATION(gui::GuiManager)

}  // namespace kuro

#endif  // GUI_IMGUI_GUI_H_
