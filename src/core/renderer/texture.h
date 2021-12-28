#ifndef CORE_RENDERER_TEXTURE_H_
#define CORE_RENDERER_TEXTURE_H_

#include <string>
#include <memory>
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

#endif  // CORE_RENDERER_TEXTURE_H_