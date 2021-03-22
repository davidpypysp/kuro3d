#ifndef SRC_CORE_RENDERER_MATERIAL_H_
#define SRC_CORE_RENDERER_MATERIAL_H_

#include "src/core/renderer/shader.h"

namespace kuro {

class Material {
 public:
  Material();

  virtual void Use() = 0;

 protected:
  std::shared_ptr<Shader> shader_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MATERIAL_H_