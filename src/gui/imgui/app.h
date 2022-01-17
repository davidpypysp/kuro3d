#ifndef GUI_IMGUI_APP_H_
#define GUI_IMGUI_APP_H_

#include "src/gui/imgui/context.h"

namespace kuro {

namespace gui {

class App {
 public:
  App();

  void Run();

 protected:
  std::shared_ptr<Context> context_;
};

}  // namespace gui

}  // namespace kuro

#endif