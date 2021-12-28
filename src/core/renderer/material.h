#ifndef CORE_RENDERER_MATERIAL_H_
#define CORE_RENDERER_MATERIAL_H_

#include "src/core/renderer/shader.h"

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

#endif  // CORE_RENDERER_MATERIAL_H_