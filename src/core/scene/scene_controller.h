#ifndef CORE_SCENE_SCENE_CONTROLLER_H_
#define CORE_SCENE_SCENE_CONTROLLER_H_

#include <memory>

#include "src/utils/ioc_container.h"
#include "src/core/scene/scene_manager.h"

namespace kuro {

class SceneController : public IocContainer {
 public:
  SceneController();
};

}  // namespace kuro

#endif
