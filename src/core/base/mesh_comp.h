#ifndef CORE_BASE_MESH_COMP_H_
#define CORE_BASE_MESH_COMP_H_

#include "src/core/base/visual_comp.h"
#include "src/core/base/mesh_data.h"

namespace kuro {
namespace core {

class MeshComp : public VisualComp {
 public:
  MeshComp(std::shared_ptr<Geometry> geometry,
           std::shared_ptr<Material> material) {
    mesh_data_.geometry = geometry;
    mesh_data_.material = material;
  }

  MeshData& mesh_data() { return mesh_data_; }

 protected:
  MeshData mesh_data_;
};

} /* namespace core */
}  //  namespace kuro

#endif