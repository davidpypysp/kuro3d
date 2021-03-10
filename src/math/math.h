#ifndef SRC_MATH_MATH_H_
#define SRC_MATH_MATH_H_

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/string_cast.hpp>

namespace kuro {
using namespace glm;

namespace math {
using namespace glm;

constexpr float r2d = 180.0 / M_PI;
constexpr float d2r = M_PI / 180.0;

}  // namespace math

}  // namespace kuro

#endif  // SRC_MATH_MATH_H_
