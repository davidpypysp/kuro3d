#include "src/core/scene/scene_node.h"
#include "src/core/scene/scene_manager.h"
#include "src/core/elements/pack.h"

namespace kuro {

SceneNode::SceneNode(const std::string& name) : NodeBase(name) {
  SetLocalTransform(mat4(1.0));
  std::cout << "transform " << math::to_string(transform_) << std::endl;
  std::cout << "position" << math::to_string(translation_) << std::endl;
  std::cout << "rotation" << math::to_string(rotation_) << std::endl;
  std::cout << "scale " << math::to_string(scale_) << std::endl;
}

std::shared_ptr<SceneNode> SceneNode::Create(const std::string& name) {
  auto scene_node = std::make_shared<SceneNode>(name);
  return scene_node;
}

float* SceneNode::TranslationPtr() { return &translation_[0]; }
float* SceneNode::RotationPtr() { return &rotation_[0]; }
float* SceneNode::ScalePtr() { return &scale_[0]; }

void SceneNode::BindPack(std::shared_ptr<Pack> pack) {
  this->packs_.push_back(pack);
  pack->set_scene_node(shared_from_this());
}

void SceneNode::UnbindPack(std::shared_ptr<Pack> pack) {}

PackList& SceneNode::GetPacks() { return packs_; }

void SceneNode::AddChildSceneNode(std::shared_ptr<SceneNode> scene_node) {
  AddChild(scene_node);
  scene_manager_->AddSceneNode(scene_node);
}

void SceneNode::SetLocalTransform(const mat4& transform) {
  transform_ = transform;
  UpdateLocalTransform();
}

void SceneNode::UpdateLocalTransform() {
  quat rotation_quat;
  vec3 skew;
  vec4 perspective;
  math::decompose(transform_, scale_, rotation_quat, translation_, skew,
                  perspective);
  rotation_quat = math::conjugate(rotation_quat);
  rotation_ = math::eulerAngles(rotation_quat);
}

}  // namespace kuro
