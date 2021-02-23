#ifndef KURO_CORE_SCENE_SCENE_NODE_H_
#define KURO_CORE_SCENE_SCENE_NODE_H_

#include "src/core/elements/pack.h"
#include "src/core/scene/scene_manager.h"
#include "src/core/scene/node_base.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <memory>

namespace kuro {

typedef std::vector<std::shared_ptr<Pack>> PackList;

class SceneNode : public NodeBase {
 public:
  SceneNode();
  SceneNode(const std::string name);

  void BindPack(std::shared_ptr<Pack> pack);
  void UnbindPack(std::shared_ptr<Pack> pack);

  PackList& GetPacks();

  template <class SN>
  std::shared_ptr<SN> CreateChildSceneNode(const std::string& name);

  glm::vec3 position() const { return position_; }
  glm::vec3 rotation() const { return rotation_; }
  glm::vec3 scale() const { return scale_; }

  void set_scene_manager(std::shared_ptr<SceneManager> scene_manager) {
    scene_manager_ = scene_manager;
  }

 protected:
  // transformation
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;

  std::shared_ptr<SceneManager> scene_manager_;

  // children
  PackList packs_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_NODE_H_