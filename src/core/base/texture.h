#ifndef CORE_BASE_TEXTURE_H_
#define CORE_BASE_TEXTURE_H_

#include <string>
#include <memory>

namespace kuro {
namespace core {

struct TextureHandle {};

enum TextureType { DIFFUSE, SPECULAR, NORMAL, HEIGHT };

enum TextureFormat { RED, RGB, RGBA };

struct Texture {
  std::shared_ptr<TextureHandle> handle;
  TextureType type;
  std::string path;
};

} /* namespace core */
}  //  namespace kuro

#endif  //  CORE_BASE_TEXTURE_H_