#ifndef KURO_CORE_ELEMENTS_ATOM_H_
#define KURO_CORE_ELEMENTS_ATOM_H_

#include "src/core/renderer/shader.h"
#include <memory>

namespace kuro {

// the most basic unit of all elements
class Atom {
 public:
  Atom();

  virtual void Draw(const Shader &shader);
};

}  // namespace kuro

#endif  // KURO_CORE_ELEMENTS_BASE_ATOM_H_