#include "src/core/renderer/shader.h"

namespace kuro {

Shader::Shader(const char *vertex_path, const char *fragment_path,
               const char *geometry_path) {
  std::string vertex_code;
  std::string fragment_code;
  std::string geometry_code;
  std::ifstream vshader_file;
  std::ifstream fshader_file;
  std::ifstream gshader_file;

  vshader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fshader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  gshader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vshader_file.open(vertex_path);
    fshader_file.open(fragment_path);
    std::stringstream vshader_stream, fshader_stream;

    vshader_stream << vshader_file.rdbuf();
    fshader_stream << fshader_file.rdbuf();

    vshader_file.close();
    fshader_file.close();

    vertex_code = vshader_stream.str();
    fragment_code = fshader_stream.str();
    if (geometry_path != nullptr) {
      gshader_file.open(geometry_path);
      std::stringstream gshader_stream;
      gshader_stream << gshader_file.rdbuf();
      gshader_file.close();
      geometry_code = gshader_stream.str();
    }
  } catch (std::ifstream::failure &e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
  }

  const char *vshader_code = vertex_code.c_str();
  const char *fshader_code = fragment_code.c_str();
  // 2. compile shaders
  unsigned int vertex, fragment;
  // vertex shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vshader_code, NULL);
  glCompileShader(vertex);
  CheckCompileErrors(vertex, "VERTEX");
  // fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fshader_code, NULL);
  glCompileShader(fragment);
  CheckCompileErrors(fragment, "FRAGMENT");
  // if geometry shader is given, compile geometry shader
  unsigned int geometry;
  if (geometry_path != nullptr) {
    const char *gshader_code = geometry_code.c_str();
    geometry = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometry, 1, &gshader_code, NULL);
    glCompileShader(geometry);
    CheckCompileErrors(geometry, "GEOMETRY");
  }
  // shader Program
  id_ = glCreateProgram();
  glAttachShader(id_, vertex);
  glAttachShader(id_, fragment);
  if (geometry_path != nullptr) glAttachShader(id_, geometry);
  glLinkProgram(id_);
  CheckCompileErrors(id_, "PROGRAM");
  // delete the shaders as they're linked into our program now and no longer
  // necessery
  glDeleteShader(vertex);
  glDeleteShader(fragment);
  if (geometry_path != nullptr) glDeleteShader(geometry);
}

void Shader::Use() { glUseProgram(id_); }

void Shader::CheckCompileErrors(GLuint shader, std::string type) {
  GLint success;
  GLchar infoLog[1024];
  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout
          << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
          << infoLog
          << "\n -- --------------------------------------------------- -- "
          << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout
          << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
          << infoLog
          << "\n -- --------------------------------------------------- -- "
          << std::endl;
    }
  }
}

}  // namespace kuro