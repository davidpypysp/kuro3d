#ifndef CORE_RENDERER_SHADER_MANAGER_H_
#define CORE_RENDERER_SHADER_MANAGER_H_

#include <memory>
#include <unordered_map>

#include "src/core/base/shader_handle.h"
#include "src/core/renderer/shader_program.h"
#include "src/utils/type_annotation.h"

namespace kuro {

class ShaderManager {
 public:
  ShaderManager();
  void Init();

  std::shared_ptr<ShaderProgram> GetShaderProgram(
      std::shared_ptr<ShaderHandle> shader_handle);

  void SetShaderProgram(std::shared_ptr<ShaderHandle> shader_handle,
                        std::shared_ptr<ShaderProgram> shader_program);

 protected:
  std::unordered_map<std::shared_ptr<ShaderHandle>,
                     std::shared_ptr<ShaderProgram>>
      shader_map_;
};

REGISTER_TYPE_ANNOTATION(ShaderManager)

}  // namespace kuro

#endif  // CORE_RENDERER_SHADER_MANAGER_H_