#ifndef UTILS_TYPE_ANNOTATION_H_
#define UTILS_TYPE_ANNOTATION_H_

#include <string>

namespace kuro {

template <typename T>
struct TypeAnnotation {
  static std::string Name() { return "NotExisted"; }
};

#define REGISTER_TYPE_ANNOTATION(className)          \
  template <>                                        \
  struct TypeAnnotation<className> {                 \
    static std::string Name() { return #className; } \
  };

}  // namespace kuro

#endif