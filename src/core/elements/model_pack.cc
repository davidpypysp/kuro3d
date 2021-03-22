#include "src/core/elements/model_pack.h"
#include "src/core/engine.h"

namespace kuro {

ModelPack::ModelPack(const std::string &path) {
  Engine::GetModelLoader()->LoadModel(path, &meshes_);
}

void ModelPack::Draw(std::shared_ptr<Shader> shader) {
  for (unsigned int i = 0; i < meshes_.size(); i++) {
    DrawMesh(meshes_[i], shader);
  }
}

void ModelPack::DrawMesh(const Mesh &mesh, std::shared_ptr<Shader> shader) {
  unsigned int diffuse_num = 0;
  unsigned int specular_num = 0;
  unsigned int normal_num = 0;
  unsigned int height_num = 0;

  auto textures = mesh.textures;

  for (unsigned int i = 0; i < textures.size(); i++) {
    std::string name, number;
    switch (textures[i]->type) {
      case TextureType::DIFFUSE:
        name = "texture_diffuse";
        number = std::to_string(++diffuse_num);
        break;
      case TextureType::SPECULAR:
        name = "texture_specular";
        number = std::to_string(++specular_num);
        break;
      case TextureType::NORMAL:
        name = "texture_normal";
        number = std::to_string(++normal_num);
        break;
      case TextureType::HEIGHT:
        name = "texture_height";
        number = std::to_string(++height_num);
        break;
    }

    shader->SetInt(name + number, i);
    Engine::GetRenderAPI()->EnableTextureUnit(i, textures[i]->handle);
  }

  Engine::GetRenderAPI()->DrawMeshInstance(mesh.handle);
}

}  // namespace kuro
