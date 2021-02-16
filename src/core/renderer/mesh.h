#ifndef KURO_CORE_RENDERER_MESH_H_
#define KURO_CORE_RENDERER_MESH_H_

#include "src/core/renderer/shader.h"
#include <glm/glm.hpp>
#include <vector>

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

class Mesh {
 public:
  Mesh(const std::vector<Vertex> &vertices,
       const std::vector<unsigned int> &indices,
       const std::vector<Texture> &textures);

  void Draw(const Shader &shader);

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

#endif