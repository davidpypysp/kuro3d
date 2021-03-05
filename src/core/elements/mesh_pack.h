#ifndef SRC_CORE_ELEMENTS_MESH_PACK_H_
#define SRC_CORE_ELEMENTS_MESH_PACK_H_

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "src/core/renderer/shader.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 tex_coords;
  glm::vec3 tangent;
  glm::vec3 bitangent;
};

struct Texture {
  unsigned int id;
  std::string type;
  std::string path;
};

class MeshPack : public VisualPack {
 public:
  MeshPack(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices,
           const std::vector<Texture> &textures);

  void Draw(Shader &shader);

 private:
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
  std::vector<Texture> textures_;
  unsigned int vao_;
  unsigned int vbo_;
  unsigned int ebo_;

  void SetupMesh();
};
}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_MESH_PACK_H_
