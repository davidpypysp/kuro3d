#include <stb_image.h>
#include "src/core/renderer/renderer.h"

namespace kuro {

Renderer::Renderer() {
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");

  render_api_ = std::make_shared<GLRenderAPI>();
}

Renderer::~Renderer() {}

void Renderer::Init() {
  stbi_set_flip_vertically_on_load(true);
  render_api_->Init();
}

}  // namespace kuro
