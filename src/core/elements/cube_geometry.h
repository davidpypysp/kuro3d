#ifndef CORE_ELEMENTS_CUBE_GEOMETRY_H_
#define CORE_ELEMENTS_CUBE_GEOMETRY_H_

#include "src/core/renderer/geometry.h"

namespace kuro {
namespace core {

class CubeGeometry : public Geometry {
 public:
  CubeGeometry();

  void Setup();
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_ELEMENTS_CUBE_GEOMETRY_H_