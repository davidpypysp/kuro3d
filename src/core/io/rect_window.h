#ifndef CORE_IO_RECT_WINDOW_H_
#define CORE_IO_RECT_WINDOW_H_

namespace kuro {

struct RectWindow {
  unsigned int width;
  unsigned int height;

  void SetSize(const unsigned int w, const unsigned int h) {
    width = w;
    height = h;
  }
};

}  // namespace kuro

#endif