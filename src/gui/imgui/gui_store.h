#ifndef GUI_IMGUI_GUI_STORE_H_
#define GUI_IMGUI_GUI_STORE_H_

#include "src/core/scene/scene_node.h"

namespace kuro {

namespace gui {

struct GuiStore {
  std::shared_ptr<SceneNode> selected_scene_node;
};

}  // namespace gui

}  // namespace kuro

#endif