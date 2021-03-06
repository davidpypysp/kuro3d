#ifndef SRC_CORE_RENDERER_TEXTURE_H_
#define SRC_CORE_RENDERER_TEXTURE_H_

#include <iostream>

#include "src/core/renderer/renderer_type.h"

namespace kuro {

struct Texture {
  std::shared_ptr<TextureHandle> handle;
  std::string type;
  std::string path;
};

enum TextureFormat { RED, RGB, RGBA };

void InitTextureLoader();

std::shared_ptr<TextureHandle> LoadTextureFromFile(const char *path,
                                                   const std::string &directory,
                                                   const bool gamma = false);

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_TEXTURE_H_