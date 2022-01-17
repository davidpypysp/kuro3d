#ifndef CORE_ELEMENTS_VISUAL_PACK_H_
#define CORE_ELEMENTS_VISUAL_PACK_H_

#include "src/core/elements/pack.h"
#include "src/core/base/shader.h"

namespace kuro {
namespace core {

// pack could be render into world
class VisualPack : public Pack {
 public:
  VisualPack(){};
  ~VisualPack(){};

  virtual void Render() = 0;
};

} /* namespace core */
}  //  namespace kuro

#endif  // CORE_ELEMENTS_VISUAL_PACK_H_