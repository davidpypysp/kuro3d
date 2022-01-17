#ifndef CORE_BASE_MESH_FLAT_MATERIAL_H_
#define CORE_BASE_MESH_FLAT_MATERIAL_H_

#include "src/core/base/material.h"

namespace kuro {

struct MeshFlatMaterial : public Material {
  static std::shared_ptr<ShaderHandle> shader_handle;

  std::shared_ptr<ShaderHandle> GetShaderHandle() { return shader_handle; }
};

}  // namespace kuro

#endif