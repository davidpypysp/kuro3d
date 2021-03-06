#include <iostream>
#include "src/core/engine.h"
#include "src/core/elements/mesh_pack.h"

namespace kuro {

MeshPack::MeshPack(const std::vector<Vertex> &vertices,
                   const std::vector<unsigned int> &indices,
                   const std::vector<Texture> &textures) {
  this->vertices_ = vertices;
  this->indices_ = indices;
  this->textures_ = textures;

  this->SetupMesh();
}

void MeshPack::Draw(Shader &shader) {
  unsigned int diffuse_num = 1;
  unsigned int specular_num = 1;
  unsigned int normal_num = 1;
  unsigned int height_num = 1;

  for (unsigned int i = 0; i < textures_.size(); i++) {
    std::string number;
    std::string name = textures_[i].type;
    if (name == "texture_diffuse") {
      number = std::to_string(diffuse_num++);
    } else if (name == "texture_specular") {
      number = std::to_string(specular_num++);
    } else if (name == "texture_normal") {
      number = std::to_string(normal_num++);
    } else if (name == "texture_height") {
      number = std::to_string(height_num++);
    }

    shader.SetInt(name + number, i);
    Engine::GetRenderAPI()->EnableTextureUnit(i, textures_[i].handle);
  }

  Engine::GetRenderAPI()->DrawMeshInstance(vertex_handle_);
}

void MeshPack::SetupMesh() {
  vertex_handle_ =
      Engine::GetRenderAPI()->CreateMeshInstance(vertices_, indices_);
}

}  // namespace kuro