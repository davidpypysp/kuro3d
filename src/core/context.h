#ifndef CORE_CONTEXT_H_
#define CORE_CONTEXT_H_

#include "src/utils/ioc_container.h"

namespace kuro {

class Context : public IocContainer {
 public:
  Context();
};

}  // namespace kuro

#endif