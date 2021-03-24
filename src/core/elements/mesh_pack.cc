#include "src/core/elements/mesh_pack.h"
#include "src/core/engine.h"

namespace kuro {

MeshPack::MeshPack(std::shared_ptr<Geometry> geometry,
                   std::shared_ptr<Material> material)
    : geometry_(geometry), material_(material) {}

void MeshPack::Render() {
  auto shader = material_->shader();
  material_->Use();
  Engine::GetRenderAPI()->DrawMeshInstance(geometry_->handle());
}

}  // namespace kuro
