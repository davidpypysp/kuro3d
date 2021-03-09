#ifndef SRC_CORE_ELEMENTS_VISUAL_PACK_H_
#define SRC_CORE_ELEMENTS_VISUAL_PACK_H_

#include "src/core/elements/pack.h"
#include "src/core/renderer/shader.h"

namespace kuro {

// pack could be render into world
class VisualPack : public Pack {
 public:
  VisualPack();
  ~VisualPack();

  virtual void Draw(Shader &shader);
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_VISUAL_PACK_H_