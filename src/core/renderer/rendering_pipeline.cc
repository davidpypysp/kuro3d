#include "src/core/renderer/rendering_pipeline.h"

#include <memory>

#include "src/core/base/mesh_comp.h"
#include "src/core/base/mesh_basic_material.h"

namespace kuro {

void RenderingPipeline::PrepareDraw() {
  auto shader_handle = mesh_data.material->shader_handle;
  shader->Use();

  // TODO: get camera resource
  shader->SetMat4("projection", camera->GetPerspectiveMatrix());
  shader->SetMat4("view", camera->GetViewMatrix());
}

void RenderingPipeline::DrawMesh(const MeshData& mesh_data) {
  auto material = mesh_data.material;
  auto shader_handle = material->shader_handle;
  ShaderProgram shader_program;

  if (auto mesh_basic_material =
          std::dynamic_pointer_cast<MeshBasicMaterial>(mateiral)) {
    // TODO: pass wolrd transform
    // shader->SetMat4("model", scene_node_->WorldTransform());

    // use material
    unsigned int texture_num = 0;
    if (mesh_basic_material->diffuse_map) {
      shader_program->SetInt("texture_diffuse", texture_num);
      render_api_->EnableTextureUnit(texture_num++,
                                     mesh_basic_material->diffuse_map_->handle);
    }
    if (mesh_basic_material->specular_map) {
      shader_->SetInt("texture_specular", texture_num);
      render_api_->EnableTextureUnit(texture_num++, specular_map_->handle);
    }
    if (normal_map_) {
      shader_->SetInt("texture_normal", texture_num);
      render_api_->EnableTextureUnit(texture_num++, normal_map_->handle);
    }
    if (height_map_) {
      shader_->SetInt("texture_height", texture_num);
      render_api_->EnableTextureUnit(texture_num++, height_map_->handle);
    }
  }

  render_api_->DrawMeshInstance(geometry_->handle());
}

void RenderingPipeline::DrawSceneNode(std::shared_ptr<SceneNode> scene_node) {
  scene_node->UpdateTransforms();

  for (auto component : scene_node->GetComponents()) {
    if (auto mesh_comp = std::dynamic_pointer_cast<MeshComp>(component)) {
      // visual comp pass data to pipeline
      //   DrawMesh(mesh_comp)
      //   mesh_comp->Render();
    }
  }

  // recursively pass child nodes
  for (auto child_node : scene_node->child_nodes()) {
    DrawSceneNode(child_node);
  }
}

void RenderingPipeline::DrawFrame(const SceneNode& root_node) {
  PrepareDraw();

  scene_node->UpdateTransforms();

  for (auto component : scene_node->GetComponents()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualComp>(component)) {
      // visual comp pass data to pipeline
      visual_pack->Render();
    }
  }

  // recursively pass child nodes
  for (auto child_node : scene_node->child_nodes()) {
    TransferSceneNodeData(child_node);
  }
}

}  // namespace kuro