#ifndef KURO_CORE_RENDERER_RENDERER_H_
#define KURO_CORE_RENDERER_RENDERER_H_

#include "src/core/renderer/shader.h"
#include "src/core/renderer/model.h"
#include "src/core/renderer/camera.h"

namespace kuro {

class Renderer {
 public:
  Renderer(unsigned int width, unsigned int height);
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

  Camera *camera_;
  Shader *shader_;
  Model *model_;

  void InitRectangle();
  void InitModel();
  void DrawRectangle();
  void DrawModel();
};

}  // namespace kuro

#endif  // KURO_CORE_RENDERER_RENDERER_H_