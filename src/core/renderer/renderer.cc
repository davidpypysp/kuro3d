#include "src/core/renderer/renderer.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

namespace kuro {

Renderer::Renderer(const unsigned int width, const unsigned int height)
    : width_(width), height_(height) {}

void Renderer::Init() { this->InitModel(); }

void Renderer::InitRectangle() {
  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";
  const char *fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n\0";

  // build and comper shader program
  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  this->shader_program = glCreateProgram();
  glAttachShader(this->shader_program, vertexShader);
  glAttachShader(this->shader_program, fragmentShader);
  glLinkProgram(this->shader_program);
  glGetProgramiv(this->shader_program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->shader_program, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  float vertices[] = {
      0.5f,  0.5f,  0.0f,  // top right
      0.5f,  -0.5f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f,  // bottom left
      -0.5f, 0.5f,  0.0f   // top left
  };
  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  glGenVertexArrays(1, &this->vao);
  glGenBuffers(1, &this->vbo);
  glGenBuffers(1, &this->ebo);

  glBindVertexArray(this->vao);

  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
}

void Renderer::InitModel() {
  stbi_set_flip_vertically_on_load(true);
  glEnable(GL_DEPTH_TEST);

  this->camera_ = std::make_shared<Camera>(glm::vec3(0.0, 0.0, 3.0));
  this->shader_ =
      std::make_unique<Shader>("model_loading.vert", "model_loading.frag");
  this->model_ = std::make_unique<Model>("resources/backpack/backpack.obj");
}

void Renderer::Draw() { this->DrawModel(); }

void Renderer::DrawRectangle() {
  glUseProgram(this->shader_program);
  glBindVertexArray(this->vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::DrawModel() {
  shader_->Use();

  glm::mat4 projection = glm::perspective(
      glm::radians(camera_->zoom()), (float)this->width_ / (float)this->height_,
      0.1f, 100.0f);
  glm::mat4 view = camera_->GetViewMatrix();

  shader_->SetMat4("projection", projection);
  shader_->SetMat4("view", view);

  glm::mat4 model = glm::mat4(1.0);
  model = glm::translate(model, glm::vec3(0.0, 0.0, 0.0));
  model = glm::scale(model, glm::vec3(1.0, 1.0, 1.0));
  shader_->SetMat4("model", model);
  model_->Draw(*shader_);
}

void Renderer::Cleanup() {
  glDeleteVertexArrays(1, &this->vao);
  glDeleteBuffers(1, &this->vbo);
  glDeleteBuffers(1, &this->ebo);
  glDeleteProgram(this->shader_program);
}

}  // namespace kuro