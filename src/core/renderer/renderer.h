#ifndef KURO_CORE_RENDERER_RENDERER_H_
#define KURO_CORE_RENDERER_RENDERER_H_

#include "src/core/renderer/shader.h"
#include "src/core/object/model.h"
#include "src/core/scene/camera.h"
#include "src/core/scene/scene_manager.h"
#include <memory>

namespace kuro {

class Renderer {
 public:
  Renderer(const unsigned int width, const unsigned int height);
  void Init();
  void Draw();
  void Cleanup();

 private:
  unsigned int width_;
  unsigned int height_;

  int shader_program;
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;

  std::shared_ptr<Camera> camera_;
  std::shared_ptr<Shader> shader_;
  std::unique_ptr<Model> model_;
  std::unique_ptr<SceneManager> scene_manager_;

  void InitRectangle();
  void InitModel();
  void InitScene();
  void DrawRectangle();
  void DrawModel();
};

}  // namespace kuro

#endif  // KURO_CORE_RENDERER_RENDERER_H_