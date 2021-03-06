#ifndef SRC_CORE_ELEMENTS_MESH_PACK_H_
#define SRC_CORE_ELEMENTS_MESH_PACK_H_

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "src/core/renderer/shader.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {

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
  std::shared_ptr<VertexHandle> vertex_handle_;

  void SetupMesh();
};
}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_MESH_PACK_H_
