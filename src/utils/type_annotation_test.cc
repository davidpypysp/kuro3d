#include <gtest/gtest.h>
#include <memory>

#include "src/utils/type_annotation.h"

namespace kuro {

REGISTER_TYPE_ANNOTATION(float)
REGISTER_TYPE_ANNOTATION(std::string)

// Demonstrate some basic assertions.
TEST(TypeAnnotationTest, BasicAssertions) {
  std::string name = TypeAnnotation<std::string>::Name();
  std::cout << "name: " << name << std::endl;

  std::cout << "type name: " << TypeAnnotation<float>::Name() << std::endl;
  std::cout << "type name: " << TypeAnnotation<std::string>::Name()
            << std::endl;
}

}  // namespace kuro