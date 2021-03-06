#ifndef SRC_CORE_ELEMENTS_MODEL_PACK_H_
#define SRC_CORE_ELEMENTS_MODEL_PACK_H_

#include <iostream>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "src/core/elements/mesh_pack.h"
#include "src/core/elements/visual_pack.h"
#include "src/core/engine.h"

namespace kuro {

static std::shared_ptr<TextureHandle> TextureFromFile(
    const char *path, const std::string &directory, const bool gamma = false) {
  std::shared_ptr<TextureHandle> texture_handle = nullptr;

  std::string filename = directory + '/' + std::string(path);
  int width, height, component_num;
  unsigned char *data =
      stbi_load(filename.c_str(), &width, &height, &component_num, 0);
  if (data) {
    TextureFormat format = TextureFormat::RGB;
    if (component_num == 1) {
      format = TextureFormat::RED;
    } else if (component_num == 4) {
      format = TextureFormat::RGBA;
    }

    texture_handle = Engine::GetRenderAPI()->CreateTextureInstance(
        data, width, height, format);
  } else {
    std::cout << "Texture failed to load at path: " << path << std::endl;
  }
  stbi_image_free(data);
  return texture_handle;
}

class ModelPack : public VisualPack {
 public:
  ModelPack(const std::string &path, const bool gamma = false);

  void Draw(Shader &shader);

 private:
  std::vector<Texture> textures_loaded_;
  std::vector<MeshPack> meshes_;
  std::string directory_;
  bool gamma_correction_;

  void LoadModel(const std::string &path);

  void ProcessNode(aiNode *node, const aiScene *scene);

  MeshPack ProcessMesh(aiMesh *mesh, const aiScene *scene);

  std::vector<Texture> LoadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                            const std::string &typeName);
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MODEL_PACK_H_