#include "src/core/renderer/renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

namespace kuro {

Renderer::Renderer(const unsigned int width, const unsigned int height)
    : width_(width), height_(height) {
  std::cout << "make" << std::endl;
  scene_manager_ = std::make_shared<SceneManager>();
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");
  std::cout << "make after" << std::endl;
}

void Renderer::Init() {
  stbi_set_flip_vertically_on_load(true);
  glEnable(GL_DEPTH_TEST);

  scene_manager_->CreateDefaultScene();
}

void Renderer::Draw() { this->scene_manager_->Draw(shader_); }

void Renderer::Cleanup() {}

}  // namespace kuro
