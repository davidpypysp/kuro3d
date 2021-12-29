#ifndef CORE_RENDERER_GEOMETRY_H_
#define CORE_RENDERER_GEOMETRY_H_

#include <vector>
#include <memory>

#include "src/core/base/vertex.h"

namespace kuro {

struct GeometryHandle {};

class Geometry {
 public:
  Geometry();
  Geometry(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices_);

  void Setup();

  std::shared_ptr<GeometryHandle> handle() { return handle_; }

 protected:
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
  std::shared_ptr<GeometryHandle> handle_;
};

}  // namespace kuro

#endif  // CORE_RENDERER_GEOMETRY_H_