#ifndef CORE_SCENE_DEFAULT_SCENARIO_H_
#define CORE_SCENE_DEFAULT_SCENARIO_H_

#include "src/core/context.h"

#include "src/core/scene/scene_manager.h"
#include "src/core/loader/model_loader.h"
#include "src/core/base/camera_comp.h"

namespace kuro {

void CreateDefaultScene(std::shared_ptr<Context> context) {
  auto scene_manager = context->Resolve<SceneManager>();
  auto model_loader = context->Resolve<ModelLoader>();

  auto root_node = scene_manager->root_node();

  // TODO: refactor camera generation
  auto camera_node = scene_manager->CreateSceneNode(
      "default_camera", scene_manager->root_node(), vec3(0, 0, 8));
  auto camera_comp = std::make_shared<CameraComp>();
  camera_node->BindComponent(camera_comp);
  scene_manager->set_camera_node(camera_node);

  auto model_node =
      model_loader->LoadModel("resources/backpack/backpack.obj", scene_manager);
  root_node->AddChildNode(model_node);

  // example cube
  // auto example_node2 =
  //     CreateSceneNode<SceneNode>("example_cube", root_node_, vec3(0, 0,
  //     2));

  // auto cube_geometry = std::make_shared<CubeGeometry>();
  // auto mesh_flat_material = std::make_shared<MeshFlatMaterial>();
  // std::shared_ptr<MeshPack> cube_mesh_pack =
  //     std::make_shared<MeshPack>(cube_geometry, mesh_flat_material);
  // example_node2->BindPack(cube_mesh_pack);
}

}  // namespace kuro

#endif