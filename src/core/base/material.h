#ifndef CORE_BASE_MATERIAL_H_
#define CORE_BASE_MATERIAL_H_

#include "src/core/base/shader_handle.h"

namespace kuro {

struct Material {
  std::shared_ptr<ShaderHandle> shader_handle;
};

}  // namespace kuro

#endif  //  CORE_BASE_MATERIAL_H_