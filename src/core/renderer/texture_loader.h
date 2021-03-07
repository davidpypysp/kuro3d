#ifndef SRC_CORE_RENDERER_TEXTURE_LOADER_H_
#define SRC_CORE_RENDERER_TEXTURE_LOADER_H_

#include <string>
#include <vector>
#include "src/core/renderer/texture.h"

namespace kuro {

class TextureLoader {
 public:
  TextureLoader();
  std::shared_ptr<Texture> AcquireTexture(const std::string &path,
                                          const TextureType &type);

 private:
  std::shared_ptr<TextureHandle> LoadTextureFromFile(const char *path);

  std::vector<std::shared_ptr<Texture>> texture_instances;
};

}  // namespace kuro

#endif  // SRC_CORE?RENDERER_TEXTURE_LOADER_H_
