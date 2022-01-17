#include "src/core/default_scenario.h"

#include "src/core/scene/scene_manager.h"
#include "src/core/loader/model_loader.h"
#include "src/core/base/camera_comp.h"

namespace kuro {
namespace core {

void CreateDefaultScene(std::shared_ptr<Context> context) {
  auto scene_manager = context->Resolve<SceneManager>();
  auto model_loader = context->Resolve<ModelLoader>();

  auto root_node = scene_manager->root_node();

  // TODO: refactor camera generation
  auto camera_node = scene_manager->CreateSceneNode(
      "default_camera", scene_manager->root_node(), vec3(0, 0, 0));
  auto camera_comp = std::make_shared<CameraComp>();
  camera_node->BindComponent(camera_comp);
  scene_manager->set_camera_node(camera_node);

  // Create cube node
  //   auto cube_node = model_loader->LoadCube(scene_manager);
  //   cube_node->SetLocalTranslation(vec3(0, 0, 2));
  //   root_node->AddChildNode(cube_node);

  auto model_node =
      model_loader->LoadModel("resources/backpack/backpack.obj", scene_manager);
  model_node->SetLocalTranslation(vec3(0, 0, -15));
  root_node->AddChildNode(model_node);
}

}  // namespace core
}  //  namespace kuro
