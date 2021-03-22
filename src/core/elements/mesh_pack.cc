#include "src/core/elements/mesh_pack.h"

namespace kuro {

void MeshPack::Render() {
  material_->Use();
  Engine::GetRenderAPI()->DrawMeshInstance(geometry_->handle());
}

}  // namespace kuro
