#ifndef CORE_ELEMENTS_MESH_PACK_H_
#define CORE_ELEMENTS_MESH_PACK_H_

#include "src/core/base/material.h"
#include "src/core/renderer/geometry.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {
namespace core {

class MeshPack : public VisualPack {
 public:
  MeshPack(std::shared_ptr<Geometry> geometry,
           std::shared_ptr<Material> material);

  void Render();

 protected:
  void PrepareShader();
  std::shared_ptr<Geometry> geometry_;
  std::shared_ptr<Material> material_;
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_ELEMENTS_MESH_PACK_H_
