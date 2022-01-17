#ifndef CORE_SCENE_DEFAULT_SCENARIO_H_
#define CORE_SCENE_DEFAULT_SCENARIO_H_

#include "src/core/context.h"

#include "src/core/scene/scene_manager.h"
#include "src/core/loader/model_loader.h"
#include "src/core/base/camera_comp.h"
#include "src/core/base/cube_geometry.h"
#include "src/core/base/mesh_flat_material.h"
#include "src/core/base/mesh_basic_material.h"

namespace kuro {
namespace core {

void CreateDefaultScene(std::shared_ptr<Context> context);

} /* namespace core */
}  //  namespace kuro

#endif