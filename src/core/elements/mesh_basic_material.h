#ifndef SRC_CORE_ELEMENTS_MESH_BASIC_MATERIAL_H_
#define SRC_CORE_ELEMENTS_MESH_BASIC_MATERIAL_H_

#include "src/core/renderer/material.h"
#include "src/core/renderer/texture.h"

namespace kuro {

class MeshBasicMaterial : public Material {
 public:
  MeshBasicMaterial();

  void Use();

 protected:
  std::shared_ptr<Texture> diffuse_map_;
  std::shared_ptr<Texture> specular_map_;
  std::shared_ptr<Texture> normal_map_;
  std::shared_ptr<Texture> height_map_;
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_MESH_BASIC_MATERIAL_H_
