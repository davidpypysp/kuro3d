#include <gtest/gtest.h>

#include "src/core/base/camera_comp.h"

namespace kuro {  namespace core {

TEST(CameraCompTest, BasicAssertions) {
  CameraComp camera_comp;

  EXPECT_EQ(camera_comp.zoom(), 45.0);
}

} /* namespace core */
}  //  namespace kuro
