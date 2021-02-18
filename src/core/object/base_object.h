#ifndef KURO_CORE_OBJECT_BASE_OBJECT_H_
#define KURO_CORE_OBJECT_BASE_OBJECT_H_

#include "src/core/renderer/shader.h"
#include <memory>

namespace kuro {

class BaseObject {
 public:
  BaseObject();

  virtual void Draw(const Shader &shader);
};

}  // namespace kuro

#endif  // KURO_CORE_OBJECT_BASE_OBJECT_H_