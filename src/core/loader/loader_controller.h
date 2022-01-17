#ifndef CORE_LOADER_LOADER_CONTROLLER_H_
#define CORE_LOADER_LOADER_CONTROLLER_H_

#include <memory>

#include "src/utils/ioc_container.h"

namespace kuro {

class LoaderController : public IocContainer {
 public:
  LoaderController();
};

}  // namespace kuro

#endif