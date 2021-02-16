#ifndef KURO_CORE_RENDERER_SHADER_H_
#define KURO_CORE_RENDERER_SHADER_H_

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace kuro {

class Shader {
 public:
  unsigned int id_;
  unsigned int id() const { return id_; }

  Shader(const char *vertex_path, const char *fragment_path,
         const char *geometry_path = nullptr);

  void Use();
  // utility uniform functions
  // ------------------------------------------------------------------------
  void SetBool(const std::string &name, const bool value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
  }
  // ------------------------------------------------------------------------
  void SetInt(const std::string &name, const int value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
  }
  // ------------------------------------------------------------------------
  void SetFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
  }
  // ------------------------------------------------------------------------
  void SetVec2(const std::string &name, const glm::vec2 &value) const {
    glUniform2fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
  }
  void SetVec2(const std::string &name, const float x, const float y) const {
    glUniform2f(glGetUniformLocation(id_, name.c_str()), x, y);
  }
  // ------------------------------------------------------------------------
  void SetVec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
  }
  void SetVec3(const std::string &name, const float x, const float y,
               const float z) const {
    glUniform3f(glGetUniformLocation(id_, name.c_str()), x, y, z);
  }
  // ------------------------------------------------------------------------
  void SetVec4(const std::string &name, const glm::vec4 &value) const {
    glUniform4fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
  }
  void SetVec4(const std::string &name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(id_, name.c_str()), x, y, z, w);
  }
  // ------------------------------------------------------------------------
  void SetMat2(const std::string &name, const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE,
                       &mat[0][0]);
  }
  // ------------------------------------------------------------------------
  void SetMat3(const std::string &name, const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE,
                       &mat[0][0]);
  }
  // ------------------------------------------------------------------------
  void SetMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE,
                       &mat[0][0]);
  }

 private:
  // utility function for checking shader compilation/linking errors.
  // ------------------------------------------------------------------------
  void CheckCompileErrors(GLuint shader, std::string type);
};

}  // namespace kuro

#endif  // KURO_CORE_RENDERER_SHADER_H_
