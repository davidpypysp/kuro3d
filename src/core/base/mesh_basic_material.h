#ifndef CORE_BASE_MESH_BASIC_MATERIAL_H_
#define CORE_BASE_MESH_BASIC_MATERIAL_H_

#include "src/core/base/material.h"
#include "src/core/base/texture.h"

namespace kuro {

struct MeshBasicMaterial : public Material {
  static std::shared_ptr<ShaderHandle> shader_handle;

  std::shared_ptr<ShaderHandle> GetShaderHandle();

  std::shared_ptr<Texture> diffuse_map;
  std::shared_ptr<Texture> specular_map;
  std::shared_ptr<Texture> normal_map;
  std::shared_ptr<Texture> height_map;
};

}  // namespace kuro

#endif