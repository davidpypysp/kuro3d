#ifndef SRC_CORE_ELEMENTS_VISUAL_PACK_H_
#define SRC_CORE_ELEMENTS_VISUAL_PACK_H_

#include "src/core/elements/pack.h"

namespace kuro {

// pack could be render into world
class VisualPack : public Pack {
 public:
  VisualPack();
  ~VisualPack();

  virtual void Draw(const Shader &shader);
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_VISUAL_PACK_H_