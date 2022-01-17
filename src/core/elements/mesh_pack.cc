#include "src/core/elements/mesh_pack.h"

#include "src/core/engine.h"

namespace kuro {
namespace core {

MeshPack::MeshPack(std::shared_ptr<Geometry> geometry,
                   std::shared_ptr<Material> material)
    : geometry_(geometry), material_(material) {}

void MeshPack::Render() {
  PrepareShader();
  material_->Use();
  Engine::GetRenderAPI()->DrawMeshInstance(geometry_->handle());
}

void MeshPack::PrepareShader() {
  auto shader = material_->shader();
  shader->Use();

  auto scene_manager = Engine::GetSceneManager();
  auto camera = scene_manager->current_camera();
  shader->SetMat4("projection", camera->GetPerspectiveMatrix());
  shader->SetMat4("view", camera->GetViewMatrix());

  shader->SetMat4("model", scene_node_->WorldTransform());
}

} /* namespace core */
}  //  namespace kuro
