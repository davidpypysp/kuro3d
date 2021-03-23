#ifndef SRC_CORE_ELEMENTS_CUBE_GEOMETRY_H_
#define SRC_CORE_ELEMENTS_CUBE_GEOMETRY_H_

#include "src/core/renderer/geometry.h"

namespace kuro {

class CubeGeometry : public Geometry {
 public:
  CubeGeometry();

  void Setup();
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_CUBE_GEOMETRY_H_