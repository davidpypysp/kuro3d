#include "src/core/renderer/mesh.h"
#include "src/core/engine.h"

namespace kuro {

Mesh::Mesh(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices,
           const std::vector<std::shared_ptr<Texture>> &textures)
    : vertices(vertices), indices(indices), textures(textures) {
  Setup();
}

void Mesh::Setup() {
  handle = Engine::GetRenderAPI()->CreateGeometryInstance(vertices, indices);
}

}  // namespace kuro