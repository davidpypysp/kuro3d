#ifndef SRC_CORE_RENDERER_MODEL_LOADER_H_
#define SRC_CORE_RENDERER_MODEL_LOADER_H_

#include <string>
#include <vector>

#include "src/core/renderer/mesh.h"

namespace kuro {

class ModelLoader {
 public:
  ModelLoader();

  void LoadModel(const std::string &path, std::vector<Mesh> *meshes);
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_MODEL_LOADER_H_