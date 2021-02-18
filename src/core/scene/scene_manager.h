#ifndef KURO_CORE_SCENE_SCENE_MANAGER_H_
#define KURO_CORE_SCENE_SCENE_MANAGER_H_

#include "src/core/scene/scene_node.h"
#include "src/core/scene/camera.h"
#include "src/core/renderer/shader.h"
#include <memory>

namespace kuro {

class SceneManager {
 public:
  SceneManager();
  void InitDefaultScene();
  void Draw(std::shared_ptr<Shader> shader);
  void DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                    std::shared_ptr<Shader> shader,
                    std::shared_ptr<Camera> camera);
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node,
                     std::shared_ptr<Shader> shader,
                     std::shared_ptr<Camera> camera);

 private:
  std::shared_ptr<SceneNode> root_node_;
  std::shared_ptr<Camera> current_camera_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_MANAGER_H_