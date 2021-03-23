#ifndef SRC_CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_
#define SRC_CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_

#include "src/core/renderer/material.h"

namespace kuro {

class MeshFlatMaterial : public Material {
 public:
  MeshFlatMaterial();

  void Use();
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_MESH_FLAT_MATERIAL_H_