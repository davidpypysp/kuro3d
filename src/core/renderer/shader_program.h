#ifndef CORE_BASE_SHADER_PROGRAM_H_
#define CORE_BASE_SHADER_PROGRAM_H_

#include <string>
#include <memory>

#include "src/core/base/shader_handle.h"

namespace kuro {
class ShaderProgram {
 public:
  ShaderProgram();

  void Setup(std::shared_ptr<ShaderHandle> shader_handle);

  void Use();
};
}  // namespace kuro

#endif