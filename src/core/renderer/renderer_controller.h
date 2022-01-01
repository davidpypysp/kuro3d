#ifndef CORE_RENDERER_RENDERER_CONTROLLER_H_
#define CORE_RENDERER_RENDERER_CONTROLLER_H_

#include <memory>

#include "src/core/base/ioc_container.h"

namespace kuro {

class RendererController : public IocContainer {
  RendererController();

  void ResolveDependencies();
};

}  // namespace kuro

#endif