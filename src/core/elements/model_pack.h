#ifndef SRC_CORE_ELEMENTS_MODEL_PACK_H_
#define SRC_CORE_ELEMENTS_MODEL_PACK_H_

#include "src/core/elements/visual_pack.h"
#include "src/core/renderer/texture.h"
#include "src/core/renderer/mesh.h"

namespace kuro {

class ModelPack : public VisualPack {
 public:
  ModelPack(const std::string &path);

  void Draw(std::shared_ptr<Shader> shader);

  void Render() {}

 private:
  void DrawMesh(const Mesh &mesh, std::shared_ptr<Shader> shader);
  std::vector<Mesh> meshes_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MODEL_PACK_H_