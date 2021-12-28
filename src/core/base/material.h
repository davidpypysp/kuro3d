#ifndef CORE_BASE_MATERIAL_H_
#define CORE_BASE_MATERIAL_H_

#include "src/core/base/shader.h"

namespace kuro {

class Material {
 public:
  Material();

  virtual void Use() = 0;

  std::shared_ptr<Shader> shader() { return shader_; }

 protected:
  std::shared_ptr<Shader> shader_;
};

}  // namespace kuro

#endif  //  CORE_BASE_MATERIAL_H_