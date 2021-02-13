#ifndef KURO_CORE_RENDERER_RENDERER_H_
#define KURO_CORE_RENDERER_RENDERER_H_

namespace kuro {

class Renderer {
 public:
  Renderer();
  void Init();
  void Draw();
  void Cleanup();

 private:
  int shader_program;
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;
};

}  // namespace kuro

#endif  // KURO_CORE_RENDERER_RENDERER_H_