#ifndef CORE_CONTEXT_H_
#define CORE_CONTEXT_H_

#include "src/utils/ioc_container.h"
#include "src/core/scene/scene_controller.h"
#include "src/core/loader/loader_controller.h"
#include "src/core/renderer/renderer_controller.h"
#include "src/core/io/rect_window.h"

namespace kuro {

class Context : public IocContainer {
 public:
  Context();
};

}  // namespace kuro

#endif