#include "src/core/elements/camera_atom.h"
#include "src/core/elements/visual_pack.h"
#include "src/core/engine.h"

namespace kuro {

CameraAtom::CameraAtom(const std::string& name) : SceneAtom(name) {}

std::shared_ptr<CameraAtom> CameraAtom::Create(const std::string& name) {
  auto camera_atom = std::make_shared<CameraAtom>(name);
  auto camera_pack = std::make_shared<CameraPack>();
  camera_atom->set_camera_pack(camera_pack);
  camera_atom->BindPack(camera_pack);
  return camera_atom;
}

void CameraAtom::DrawSceneNode(SceneNode& scene_node, Shader& shader) {
  if (scene_node.GetPacks().size() == 0) {
    return;
  }
  const float kRatio =
      Engine::Instance()->window_width() / Engine::Instance()->window_height();
  mat4 projection = camera_pack_->GetPerspectiveMatrix(kRatio);
  mat4 view = camera_pack_->GetViewMatrix(translation_);

  shader.SetMat4("projection", projection);
  shader.SetMat4("view", view);

  for (auto pack : scene_node.GetPacks()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualPack>(pack)) {
      mat4 model = mat4(1.0);
      model = math::translate(model, scene_node.translation());
      model = math::scale(model, scene_node.scale());
      shader.SetMat4("model", model);
      visual_pack->Draw(shader);
    }
  }
}

}  // namespace kuro
