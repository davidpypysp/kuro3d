#ifndef CORE_BASE_SHADER_HANDLE_H_
#define CORE_BASE_SHADER_HANDLE_H_

#include <string>

namespace kuro {

struct ShaderHandle {
  std::string name;
  std::string vertex_shader_path;
  std::string fragment_shader_path;
  std::string geometry_shader_path;
};

}  // namespace kuro

#endif