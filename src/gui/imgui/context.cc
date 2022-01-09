#include "src/core/context.h"

namespace kuro {

namespace gui {

Context::Context() {
  Register<Engine>();
  Register<Gui>();
  Register<GuiStore>();
}

}  // namespace gui

}  // namespace kuro