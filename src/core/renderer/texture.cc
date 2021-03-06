// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "src/core/renderer/texture.h"
#include "src/core/engine.h"

namespace kuro {

void InitTextureLoader() { stbi_set_flip_vertically_on_load(true); }

std::shared_ptr<TextureHandle> LoadTextureFromFile(const char *path,
                                                   const std::string &directory,
                                                   const bool gamma) {
  std::shared_ptr<TextureHandle> texture_handle = nullptr;

  std::string filename = directory + '/' + std::string(path);
  int width, height, component_num;
  unsigned char *data =
      stbi_load(filename.c_str(), &width, &height, &component_num, 0);
  if (data) {
    TextureFormat format = TextureFormat::RGB;
    if (component_num == 1) {
      format = TextureFormat::RED;
    } else if (component_num == 4) {
      format = TextureFormat::RGBA;
    }

    texture_handle = Engine::GetRenderAPI()->CreateTextureInstance(
        data, width, height, format);
  } else {
    std::cout << "Texture failed to load at path: " << path << std::endl;
  }
  stbi_image_free(data);
  return texture_handle;
}

}  // namespace kuro