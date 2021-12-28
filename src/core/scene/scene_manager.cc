#include "src/core/scene/scene_manager.h"
#include "src/core/loader/model_loader.h"
#include "src/core/engine.h"

#include "src/core/elements/mesh_pack.h"
#include "src/core/elements/cube_geometry.h"
#include "src/core/elements/mesh_flat_material.h"

namespace kuro {

SceneManager::SceneManager() {}

void SceneManager::CreateDefaultScene() {
  root_node_ = CreateSceneNode<SceneNode>("root");

  // default camera
  current_camera_ =
      CreateSceneNode<CameraAtom>("default_camera", root_node_, vec3(0, 0, 8));

  // example model
  auto example_node =
      CreateSceneNode<SceneNode>("example_model", root_node_, vec3(0, 0, 0));
  Engine::GetModelLoader()->LoadModel("resources/backpack/backpack.obj",
                                      example_node);

  // example cube
  auto example_node2 =
      CreateSceneNode<SceneNode>("example_cube", root_node_, vec3(0, 0, 2));

  auto cube_geometry = std::make_shared<CubeGeometry>();
  auto mesh_flat_material = std::make_shared<MeshFlatMaterial>();
  std::shared_ptr<MeshPack> cube_mesh_pack =
      std::make_shared<MeshPack>(cube_geometry, mesh_flat_material);
  example_node2->BindPack(cube_mesh_pack);
}

}  // namespace kuro
