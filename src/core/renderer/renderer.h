#ifndef CORE_RENDERER_RENDERER_H_
#define CORE_RENDERER_RENDERER_H_

#include <memory>

#include "src/utils/dependency_helper.h"
#include "src/core/scene/scene_manager.h"
#include "src/core/renderer/rendering_pipeline.h"

namespace kuro {

class Renderer {
 public:
  Renderer();

  ~Renderer();

  void Init();

  void RenderScene();

  REGISTER_DEPENDENCY(RenderingPipeline, pipeline_)
  REGISTER_DEPENDENCY(SceneManager, scene_manager_)
};

}  // namespace kuro

#endif  // CORE_RENDERER_RENDERER_H_
