#ifndef CORE_BASE_MESH_DATA_H_
#define CORE_BASE_MESH_DATA_H_

#include "src/core/base/geometry.h"
#include "src/core/base/material.h"

namespace kuro {
namespace core {

struct MeshData {
  std::shared_ptr<Geometry> geometry;
  std::shared_ptr<Material> material;
};

}  // namespace core
}  //  namespace kuro

#endif