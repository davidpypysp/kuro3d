#ifndef SRC_CORE_RENDERER_MESH_H_
#define SRC_CORE_RENDERER_MESH_H_

#include <vector>
#include <memory>
#include "src/core/renderer/renderer_type.h"
#include "src/core/renderer/texture.h"

namespace kuro {

struct Mesh {
 public:
  Mesh(const std::vector<Vertex> &vertices,
       const std::vector<unsigned int> &indices,
       const std::vector<std::shared_ptr<Texture>> &textures);

  void Setup();

  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<std::shared_ptr<Texture>> textures;
  std::shared_ptr<GeometryHandle> handle;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MESH_H_