#include SRC_CORE_RENDERER_GEOMETRY_H_
#define SRC_CORE_RENDERER_GEOMETRY_H_

#include <vector>
#include <memory>
#include "src/core/renderer/renderer_type.h"

namespace kuro {

class Geometry {
 public:
  Geometry() {}

 protected:
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_GEOMETRY_H_