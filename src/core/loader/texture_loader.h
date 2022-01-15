#ifndef CORE_LOADER_TEXTURE_LOADER_H_
#define CORE_LOADER_TEXTURE_LOADER_H_

#include <string>
#include <vector>

#include "src/utils/dependency_helper.h"
#include "src/core/base/texture.h"
#include "src/core/renderer/render_api.h"

namespace kuro {

class TextureLoader {
 public:
  TextureLoader();

  std::shared_ptr<Texture> LoadTexture(const std::string &path,
                                       const TextureType &type);

  REGISTER_DEPENDENCY(RenderAPI, render_api_)

 private:
  std::shared_ptr<TextureHandle> LoadTextureFromFile(const char *path);

  std::vector<std::shared_ptr<Texture>> texture_instances_;
};

}  // namespace kuro

#endif  // CORE?RENDERER_TEXTURE_LOADER_H_
