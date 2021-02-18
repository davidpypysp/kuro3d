#ifndef KURO_CORE_SCENE_SCENE_OBJECT_H_
#define KURO_CORE_SCENE_SCENE_OBJECT_H_

#include "src/core/renderer/model.h"
#include <memory>

namespace kuro {

class SceneObject {
 public:
  SceneObject();

 private:
  std::shared_ptr<Model> model_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_OBJECT_H_