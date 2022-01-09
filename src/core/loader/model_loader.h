#ifndef CORE_RENDERER_MODEL_LOADER_H_
#define CORE_RENDERER_MODEL_LOADER_H_

#include <string>
#include <memory>

// assimp dependencies
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>

#include "src/core/scene/scene_manager.h"
#include "src/core/loader/texture_loader.h"
#include "src/core/base/mesh_comp.h"
#include "src/utils/type_annotation.h"

namespace kuro {

class ModelLoader {
 public:
  ModelLoader();

  std::shared_ptr<SceneNode> LoadModel(
      const std::string &path, std::shared_ptr<SceneManager> scene_manager);

  REGISTER_DEPENDENCY(TextureLoader, texture_loader_)

 protected:
  std::vector<std::shared_ptr<Texture>> LoadMaterialTextures(
      aiMaterial *ai_mat, const std::string &directory,
      const aiTextureType &ai_texture_type, const TextureType &texture_type);

  std::shared_ptr<MeshComp> ProcessMesh(aiMesh *ai_mesh,
                                        const aiScene *ai_scene,
                                        const std::string &directory);

  std::shared_ptr<SceneNode> ProcessNode(
      aiNode *ai_node, const aiScene *ai_scene, const std::string &directory,
      std::shared_ptr<SceneManager> scene_manager);
};

REGISTER_TYPE_ANNOTATION(ModelLoader)

}  // namespace kuro

#endif  // CORE_RENDERER_MODEL_LOADER_H_