#include "src/core/base/camera_comp.h"

namespace kuro {
namespace core {

// constructor with vectors
CameraComp::CameraComp(const vec3 &up, const float yaw, const float pitch)
    : front_(vec3(0.0, 0.0, -1.0)),
      movement_speed_(default_speed),
      mouse_sensitivity_(default_sensitivity),
      zoom_(default_zoom) {
  world_up_ = up;
  yaw_ = yaw;
  pitch_ = pitch;
  UpdateCameraVectors();
}

mat4 CameraComp::GetPerspectiveMatrix(const float ratio) {
  return perspective(radians(zoom_), ratio, 0.1f, 100.0f);
}

mat4 CameraComp::GetViewMatrix(const vec3 &position) {
  return lookAt(position, position + front_, up_);
}

// calculates the front vector from the CameraPack's (updated) Euler Angles
void CameraComp::UpdateCameraVectors() {
  // calculate the new Front vector
  vec3 front;
  front.x = cos(radians(yaw_)) * cos(radians(pitch_));
  front.y = sin(radians(pitch_));
  front.z = sin(radians(yaw_)) * cos(radians(pitch_));
  front_ = normalize(front);
  // also re-calculate the Right and Up vector
  right_ = normalize(
      cross(front_, world_up_));  // normalize the vectors, because their length
                                  // gets closer to 0 the more you look up or
                                  // down which results in slower movement.
  up_ = normalize(cross(right_, front_));
}

} /* namespace core */

}  // namespace kuro
