#ifndef SRC_CORE_RENDERER_TEXTURE_H_
#define SRC_CORE_RENDERER_TEXTURE_H_

#include <iostream>

#include "src/core/renderer/renderer_type.h"

namespace kuro {

enum TextureType { DIFFUSE, SPECULAR, NORMAL, HEIGHT };

enum TextureFormat { RED, RGB, RGBA };

struct Texture {
  std::shared_ptr<TextureHandle> handle;
  TextureType type;
  std::string path;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_TEXTURE_H_