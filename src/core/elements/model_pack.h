#ifndef SRC_CORE_ELEMENTS_MODEL_PACK_H_
#define SRC_CORE_ELEMENTS_MODEL_PACK_H_

#include <iostream>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>

#include "src/core/elements/mesh_pack.h"
#include "src/core/elements/visual_pack.h"
#include "src/core/renderer/texture.h"

namespace kuro {

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