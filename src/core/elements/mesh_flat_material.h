#ifndef CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_
#define CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_

#include "src/core/base/material.h"

namespace kuro {
namespace core {

class MeshFlatMaterial : public Material {
 public:
  MeshFlatMaterial();

  void Use();
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_