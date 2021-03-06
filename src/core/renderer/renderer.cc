#include "src/core/renderer/renderer.h"
#include "src/core/renderer/texture.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  InitTextureLoader();
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");
}

}  // namespace kuro
