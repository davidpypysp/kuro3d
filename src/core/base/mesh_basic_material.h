#ifndef CORE_BASE_MESH_BASIC_MATERIAL_H_
#define CORE_BASE_MESH_BASIC_MATERIAL_H_

#include "src/core/base/material.h"
#include "src/core/base/texture.h"

namespace kuro {

class MeshBasicMaterial : public Material {
 public:
  MeshBasicMaterial();

  void set_diffuse_map(std::shared_ptr<Texture> texture) {
    diffuse_map_ = texture;
  }

  void set_specular_map(std::shared_ptr<Texture> texture) {
    specular_map_ = texture;
  }

  void set_normal_map(std::shared_ptr<Texture> texture) {
    normal_map_ = texture;
  }

  void set_height_map(std::shared_ptr<Texture> texture) {
    height_map_ = texture;
  }

 protected:
  std::shared_ptr<Texture> diffuse_map_;
  std::shared_ptr<Texture> specular_map_;
  std::shared_ptr<Texture> normal_map_;
  std::shared_ptr<Texture> height_map_;
};

}  // namespace kuro

#endif