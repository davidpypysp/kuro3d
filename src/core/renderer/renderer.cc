#include <stb_image.h>
#include "src/core/renderer/renderer.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  stbi_set_flip_vertically_on_load(true);
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");
}

}  // namespace kuro
