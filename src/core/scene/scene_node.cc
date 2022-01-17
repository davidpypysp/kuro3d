#include "src/core/scene/scene_node.h"

namespace kuro {
namespace core {

SceneNode::SceneNode(const std::string& name) : NodeBase(name) {
  SetLocalTransform(mat4(1.0));
}

float* SceneNode::LocalTranslationPtr() { return &translation_[0]; }
float* SceneNode::LocalRotationPtr() { return &rotation_[0]; }
float* SceneNode::LocalScalePtr() { return &scale_[0]; }

ComponentList& SceneNode::GetComponents() { return components_; }

void SceneNode::BindComponent(std::shared_ptr<ComponentBase> comp) {
  components_.push_back(comp);
}

void SceneNode::AddChildNode(std::shared_ptr<SceneNode> scene_node) {
  AddChild(scene_node);
  scene_node->set_parent(shared_from_this());
}

mat4 SceneNode::LocalTransform() { return transform_; }

mat4 SceneNode::WorldTransform() { return world_transform_; }

void SceneNode::SetLocalTransform(const mat4& transform) {
  transform_ = transform;
  UpdateTransformComponents();

  if (parent_) {
    world_transform_ = transform_ * parent_->WorldTransform();
  } else {
    world_transform_ = transform_;
  }
}

void SceneNode::SetLocalTransform(const vec3& translation, const vec3& rotation,
                                  const vec3& scale) {
  translation_ = translation;
  rotation_ = rotation;
  scale_ = scale;
  UpdateTransforms();
}

void SceneNode::SetLocalTranslation(const vec3& translation) {
  translation_ = translation;
  UpdateTransforms();
}

void SceneNode::SetLocalRotation(const vec3& rotation) {
  rotation_ = rotation;
  UpdateTransforms();
}

void SceneNode::SetLocalScale(const vec3& scale) {
  scale_ = scale;
  UpdateTransforms();
}

void SceneNode::UpdateTransforms() {
  mat4 transform = math::translate(mat4(1.0), translation_);
  transform = math::scale(transform, scale_);
  mat4 rotation_mat =
      math::eulerAngleYXZ(rotation_.y, rotation_.x, rotation_.z);
  transform = transform * rotation_mat;
  transform_ = transform;

  if (parent_) {
    world_transform_ = transform_ * parent_->WorldTransform();
  } else {
    world_transform_ = transform_;
  }
}

void SceneNode::UpdateTransformComponents() {
  quat rotation_quat;
  vec3 skew;
  vec4 perspective;
  math::decompose(transform_, scale_, rotation_quat, translation_, skew,
                  perspective);
  rotation_quat = math::conjugate(rotation_quat);
  rotation_ = math::eulerAngles(rotation_quat);
}

} /* namespace core */
}  //  namespace kuro
