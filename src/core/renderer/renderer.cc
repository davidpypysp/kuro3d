#include "src/core/renderer/renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

namespace kuro {

Renderer::Renderer() {
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");
}

Renderer::~Renderer() {}

void Renderer::Init() {
  stbi_set_flip_vertically_on_load(true);
  glEnable(GL_DEPTH_TEST);
}

}  // namespace kuro
