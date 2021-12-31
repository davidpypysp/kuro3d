#include "src/core/renderer/rendering_pipeline.h"

#include <memory>

#include "src/core/base/camera_comp.h"
#include "src/core/base/mesh_basic_material.h"

namespace kuro {

RenderingPipeline::RenderingPipeline() {}

void RenderingPipeline::Setup() {
  // TODO: remove temp shader handle
  temp_shader_handle_ = std::make_shared<ShaderHandle>();
  temp_shader_handle_->vertex_shader_path = "mesh.vert";
  temp_shader_handle_->fragment_shader_path = "mesh_basic.vert";
  auto temp_shader_program = render_api_->CreateShaderProgram(
      temp_shader_handle_->vertex_shader_path.c_str(),
      temp_shader_handle_->fragment_shader_path.c_str(),
      temp_shader_handle_->geometry_shader_path.c_str());
  shader_manager_->SetShaderProgram(temp_shader_handle_, temp_shader_program);
}

void RenderingPipeline::PrepareDraw() {
  auto shader_program = shader_manager_->GetShaderProgram(temp_shader_handle_);

  render_api_->EnableShaderProgram(shader_program);

  if (auto camera_comp = std::dynamic_pointer_cast<CameraComp>(
          camera_node_->GetComponents()[0])) {
    // TODO: turn ratio to window height/width
    constexpr float kRatio = 800.0 / 600.0;
    render_api_->SetShaderMat4Param(shader_program, "projection",
                                    camera_comp->GetPerspectiveMatrix(kRatio));
    render_api_->SetShaderMat4Param(
        shader_program, "view",
        camera_comp->GetViewMatrix(camera_node_->translation()));
  }
}

void RenderingPipeline::DrawMesh(MeshData& mesh_data) {
  auto material = mesh_data.material;
  auto shader_program = shader_manager_->GetShaderProgram(temp_shader_handle_);

  if (auto mesh_basic_material =
          std::dynamic_pointer_cast<MeshBasicMaterial>(material)) {
    // use material
    unsigned int texture_num = 0;
    if (mesh_basic_material->diffuse_map) {
      render_api_->SetShaderIntParam(shader_program, "texture_diffuse",
                                     texture_num);
      render_api_->EnableTextureUnit(texture_num++,
                                     mesh_basic_material->diffuse_map->handle);
    }
    if (mesh_basic_material->specular_map) {
      render_api_->SetShaderIntParam(shader_program, "texture_specular",
                                     texture_num);
      render_api_->EnableTextureUnit(texture_num++,
                                     mesh_basic_material->specular_map->handle);
    }
    if (mesh_basic_material->normal_map) {
      render_api_->SetShaderIntParam(shader_program, "texture_normal",
                                     texture_num);
      render_api_->EnableTextureUnit(texture_num++,
                                     mesh_basic_material->normal_map->handle);
    }
    if (mesh_basic_material->height_map) {
      render_api_->SetShaderIntParam(shader_program, "texture_height",
                                     texture_num);
      render_api_->EnableTextureUnit(texture_num++,
                                     mesh_basic_material->height_map->handle);
    }
  }

  render_api_->DrawMeshInstance(mesh_data.geometry->handle);
}

void RenderingPipeline::DrawSceneNode(std::shared_ptr<SceneNode> scene_node) {
  scene_node->UpdateTransforms();
  auto shader_program = shader_manager_->GetShaderProgram(temp_shader_handle_);
  render_api_->SetShaderMat4Param(shader_program, "model",
                                  scene_node->WorldTransform());

  for (auto component : scene_node->GetComponents()) {
    if (auto mesh_comp = std::dynamic_pointer_cast<MeshComp>(component)) {
      // visual comp pass data to pipeline
      DrawMesh(mesh_comp->mesh_data());
    }
  }

  // recursively pass child nodes
  for (auto child_node : scene_node->child_nodes()) {
    DrawSceneNode(child_node);
  }
}

void RenderingPipeline::DrawFrame(std::shared_ptr<SceneNode> root_node) {
  PrepareDraw();
  DrawSceneNode(root_node);
}

}  // namespace kuro