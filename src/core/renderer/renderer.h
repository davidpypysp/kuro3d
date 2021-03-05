#ifndef SRC_CORE_RENDERER_RENDERER_H_
#define SRC_CORE_RENDERER_RENDERER_H_

#include <memory>
#include "src/core/renderer/shader.h"
#include "src/core/renderer/gl_render_api.h"

namespace kuro {

class Renderer {
 public:
  Renderer();
  ~Renderer();
  void Init();

  std::shared_ptr<Shader> shader() { return shader_; }

 private:
  std::shared_ptr<Shader> shader_;
  std::shared_ptr<RenderAPI> render_api_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_RENDERER_H_
