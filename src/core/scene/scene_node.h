#ifndef CORE_SCENE_SCENE_NODE_H_
#define CORE_SCENE_SCENE_NODE_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "src/math/math.h"
#include "src/core/base/component_base.h"
#include "src/utils/node_base.h"

namespace kuro {
namespace core {

typedef std::vector<std::shared_ptr<ComponentBase>> ComponentList;

class SceneNode : public NodeBase<SceneNode> {
 public:
  SceneNode(const std::string& name);

  ComponentList& GetComponents();

  void BindComponent(std::shared_ptr<ComponentBase> comp);

  void AddChildNode(std::shared_ptr<SceneNode> scene_node);

  void set_id(const uint32_t id) { id_ = id; }

  vec3 translation() const { return translation_; }

  vec3 rotation() { return rotation_; }

  vec3 scale() { return scale_; }

  float* LocalTranslationPtr();
  float* LocalRotationPtr();
  float* LocalScalePtr();

  mat4 LocalTransform();

  mat4 WorldTransform();

  void SetLocalTransform(const mat4& transform);
  void SetLocalTransform(const vec3& translation, const vec3& rotation,
                         const vec3& scale);
  void SetLocalTranslation(const vec3& translation);
  void SetLocalRotation(const vec3& rotation);
  void SetLocalScale(const vec3& scale);

  void UpdateTransforms();

 protected:
  void UpdateTransformComponents();

  uint32_t id_;

  // relative transformation
  mat4 transform_;
  mat4 world_transform_;

  vec3 translation_;
  vec3 rotation_;
  vec3 scale_;

  // children
  ComponentList components_;
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_SCENE_SCENE_NODE_H_
