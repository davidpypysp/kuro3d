// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "src/core/loader/texture_loader.h"
#include "src/core/engine.h"

namespace kuro {

TextureLoader::TextureLoader() { stbi_set_flip_vertically_on_load(true); }

std::shared_ptr<Texture> TextureLoader::LoadTexture(const std::string &path,
                                                    const TextureType &type) {
  for (unsigned int i = 0; i < texture_instances_.size(); i++) {
    if (path.compare(texture_instances_[i]->path) == 0) {
      return texture_instances_[i];
    }
  }

  auto texture = std::make_shared<Texture>();
  texture->handle = LoadTextureFromFile(path.c_str());
  texture->type = type;
  texture->path = path;
  texture_instances_.push_back(texture);
  return texture;
};

std::shared_ptr<TextureHandle> TextureLoader::LoadTextureFromFile(
    const char *path) {
  std::shared_ptr<TextureHandle> texture_handle = nullptr;

  int width, height, component_num;
  unsigned char *data = stbi_load(path, &width, &height, &component_num, 0);
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