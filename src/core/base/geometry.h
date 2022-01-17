#ifndef CORE_BASE_GEOMETRY_H_
#define CORE_BASE_GEOMETRY_H_

#include <vector>
#include <memory>

#include "src/core/base/vertex.h"

namespace kuro {
namespace core {

struct GeometryHandle {};

// Geometry info for constructing rendering data
struct Geometry {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::shared_ptr<GeometryHandle> handle;

  Geometry() {}

  Geometry(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices)
      : vertices(vertices), indices(indices) {}
};

} /* namespace core */
}  //  namespace kuro

#endif