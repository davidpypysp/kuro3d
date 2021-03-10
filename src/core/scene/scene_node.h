#ifndef SRC_CORE_SCENE_SCENE_NODE_H_
#define SRC_CORE_SCENE_SCENE_NODE_H_

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "src/math/math.h"
#include "src/utils/node_base.h"

namespace kuro {

class SceneManager;
class Pack;

typedef std::vector<std::shared_ptr<Pack>> PackList;

class SceneNode : public NodeBase<SceneNode> {
 public:
  SceneNode(const std::string& name);

  static std::shared_ptr<SceneNode> Create(const std::string& name);

  virtual const char* Type() const { return "SceneNode"; }

  void BindPack(std::shared_ptr<Pack> pack);
  void UnbindPack(std::shared_ptr<Pack> pack);
  PackList& GetPacks();

  void AddChildSceneNode(std::shared_ptr<SceneNode> scene_node);

  void set_id(const uint32_t id) { id_ = id; }

  vec3 position() const { return translation_; }
  void set_position(const vec3& position) { translation_ = position; }

  vec3 rotation() { return rotation_; }
  void set_rotation(const vec3& rotation) { rotation_ = rotation; }

  vec3 scale() { return scale_; }
  void set_scale(const vec3& scale) { scale_ = scale; }

  float* PositionPtr();
  float* RotationPtr();
  float* ScalePtr();

  std::shared_ptr<SceneManager> scene_manager() { return scene_manager_; }
  void set_scene_manager(std::shared_ptr<SceneManager> scene_manager) {
    scene_manager_ = scene_manager;
  }

 protected:
  void SetLocalTransform(const mat4& transform);
  void UpdateLocalTransform();

  uint32_t id_;

  // relative transformation
  mat4 transform_;

  vec3 translation_;
  vec3 rotation_;
  vec3 scale_;

  std::shared_ptr<SceneManager> scene_manager_;

  // children
  PackList packs_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_SCENE_NODE_H_
