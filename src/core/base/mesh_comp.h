#ifndef CORE_BASE_MESH_COMP_H_
#define CORE_BASE_MESH_COMP_H_

#include "src/core/base/visual_comp.h"
#include "src/core/base/material.h"
#include "src/core/base/geometry.h"

namespace kuro {

class MeshComp : public VisualComp {
 public:
  MeshComp(std::shared_ptr<Geometry> geometry,
           std::shared_ptr<Material> material);

 protected:
  std::shared_ptr<Geometry> geometry_;
  std::shared_ptr<Material> material_;
};

}  // namespace kuro

#endif