#include "src/core/scene/scene_manager.h"
#include "src/core/renderer/model_loader.h"
#include "src/core/engine.h"

namespace kuro {

SceneManager::SceneManager() {}

void SceneManager::CreateDefaultScene() {
  root_node_ = CreateSceneNode<SceneNode>("root");

  // default camera
  current_camera_ =
      CreateSceneNode<CameraAtom>("default_camera", root_node_, vec3(0, 0, 8));

  // example model
  auto example_node =
      CreateSceneNode<SceneNode>("example_model", root_node_, vec3(0, 0, 4));
  Engine::GetModelLoader()->LoadModel("resources/backpack/backpack.obj",
                                      example_node);
}

}  // namespace kuro
