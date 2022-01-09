#ifndef CORE_ENGINE_H_
#define CORE_ENGINE_H_

#include <memory>

#include "src/core/context.h"

namespace kuro {

class Engine {
 public:
  Engine();
  ~Engine();

  static void Init();
  static Engine* Instance();

  // TODO: window class
  void SetWindowSize(const unsigned int width, const unsigned int height);
  unsigned int window_width() const { return window_width_; }
  unsigned int window_height() const { return window_height_; }

 protected:
  static Engine* instance_;

  Context context_;

  unsigned int window_width_;
  unsigned int window_height_;
};

}  // namespace kuro

#endif  // CORE_ENGINE_H_
