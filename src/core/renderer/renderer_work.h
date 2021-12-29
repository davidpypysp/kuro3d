#ifndef CORE_RENDERER_RENDERER_WORK_H_
#define CORE_RENDERER_RENDERER_WORK_H_

#include <memory>

#include "src/core/scene/scene_manager.h"

namespace kuro {

class Renderer {
 public:
  Renderer();

  ~Renderer();

  void Init();

  void DrawScene(std::shared_ptr<SceneManager> scene_manager);
};

}  // namespace kuro

#endif  // CORE_RENDERER_RENDERER_H_