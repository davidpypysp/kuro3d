#ifndef CORE_BASE_MATERIAL_H_
#define CORE_BASE_MATERIAL_H_

#include <memory>

#include "src/core/base/shader_handle.h"

namespace kuro {

struct Material {
  virtual std::shared_ptr<ShaderHandle> GetShaderHandle() = 0;

  virtual ~Material() {}
};

}  // namespace kuro

#endif  //  CORE_BASE_MATERIAL_H_