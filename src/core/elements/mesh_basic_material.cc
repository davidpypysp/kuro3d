#include "src/core/elements/mesh_basic_material.h"
#include "src/core/engine.h"

namespace kuro {

MeshBasicMaterial::MeshBasicMaterial() {
  shader_ = Engine::GetShaderManager()->mesh_basic_shader();
}

void MeshBasicMaterial::Use() {
  unsigned int texture_num = 0;
  if (diffuse_map_) {
    shader_->SetInt("texture_diffuse1", texture_num);
    Engine::GetRenderAPI()->EnableTextureUnit(texture_num++,
                                              diffuse_map_->handle);
  }
  if (specular_map_) {
    shader_->SetInt("texture_specular1", texture_num);
    Engine::GetRenderAPI()->EnableTextureUnit(texture_num++,
                                              specular_map_->handle);
  }
  if (normal_map_) {
    shader_->SetInt("texture_normal", texture_num);
    Engine::GetRenderAPI()->EnableTextureUnit(texture_num++,
                                              normal_map_->handle);
  }
  if (height_map_) {
    shader_->SetInt("texture_height1", texture_num);
    Engine::GetRenderAPI()->EnableTextureUnit(texture_num++,
                                              height_map_->handle);
  }
}

}  // namespace kuro