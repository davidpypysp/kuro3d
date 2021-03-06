#ifndef SRC_CORE_RENDERER_MODEL_LOADER_H_
#define SRC_CORE_RENDERER_MODEL_LOADER_H_

#include <string>
#include <memory>

#include "src/core/scene/scene_node.h"

namespace kuro {

class ModelLoader {
 public:
  ModelLoader();

  void LoadModel(const std::string &path,
                 std::shared_ptr<SceneNode> scene_node);
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MODEL_LOADER_H_