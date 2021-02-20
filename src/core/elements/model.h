#ifndef KURO_CORE_ELEMENTS_MODEL_H_
#define KURO_CORE_ELEMENTS_MODEL_H_

#include "src/core/elements/mesh.h"
#include "src/core/elements/atom.h"
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace kuro {

static unsigned int TextureFromFile(const char *path,
                                    const std::string &directory,
                                    const bool gamma = false) {
  std::string filename = std::string(path);
  filename = directory + '/' + filename;

  unsigned int texture_id;
  glGenTextures(1, &texture_id);

  int width, height, component_num;
  unsigned char *data =
      stbi_load(filename.c_str(), &width, &height, &component_num, 0);
  if (data) {
    GLenum format;
    if (component_num == 1) {
      format = GL_RED;
    } else if (component_num == 3) {
      format = GL_RGB;
    } else if (component_num == 4) {
      format = GL_RGBA;
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
  } else {
    std::cout << "Texture failed to load at path: " << path << std::endl;
    stbi_image_free(data);
  }
  return texture_id;
}

class Model : public Atom {
 public:
  Model(const std::string &path, const bool gamma = false);

  void Draw(const Shader &shader);

 private:
  std::vector<Texture> textures_loaded_;
  std::vector<Mesh> meshes_;
  std::string directory_;
  bool gamma_correction_;

  void LoadModel(const std::string &path);

  void ProcessNode(aiNode *node, const aiScene *scene);

  Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);

  std::vector<Texture> LoadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                            const std::string &typeName);
};

}  // namespace kuro

#endif  // KURO_CORE_RENDERER_MODEL_H_