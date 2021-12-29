#include <gtest/gtest.h>

#include "src/core/base/shader.h"

namespace kuro {
// Demonstrate some basic assertions.
TEST(ShaderTest, BasicAssertions) {
  Shader shader("mesh.vert", "mesh_flat.frag");
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

}  // namespace kuro
