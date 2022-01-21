#include <gtest/gtest.h>

#include "src/core/engine.h"

namespace kuro {
namespace core {
// Demonstrate some basic assertions.
TEST(EngineTest, BasicAssertions) { Engine::Instance()->Init(); }

}  // namespace core
}  //  namespace kuro