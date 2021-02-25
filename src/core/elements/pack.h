#ifndef SRC_CORE_ELEMENTS_PACK_H_
#define SRC_CORE_ELEMENTS_PACK_H_

#include <memory>
#include "src/core/renderer/shader.h"

namespace kuro {

// the basic unit of all elements
class Pack {
 public:
  Pack();
  virtual ~Pack();
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_BASE_PACK_H_
