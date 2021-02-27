#include "src/core/elements/camera_pack.h"

namespace kuro {

// constructor with vectors
CameraPack::CameraPack(const glm::vec3 &up, const float yaw, const float pitch)
    : front_(glm::vec3(0.0, 0.0, -1.0)),
      movement_speed_(default_speed),
      mouse_sensitivity_(default_sensitivity),
      zoom_(default_zoom) {
  world_up_ = up;
  yaw_ = yaw;
  pitch_ = pitch;
  UpdateCameraVectors();
}

glm::mat4 CameraPack::GetPerspectiveMatrix(const float ratio) {
  return glm::perspective(glm::radians(zoom_), ratio, 0.1f, 100.0f);
}

glm::mat4 CameraPack::GetViewMatrix(const glm::vec3 &position) {
  return glm::lookAt(position, position + front_, up_);
}

// void CameraPack::ProcessMouseScroll(const float y_offset) {
//   zoom_ -= y_offset;
//   if (zoom_ < 1.0) zoom_ = 1.0;
//   if (zoom_ > 45.0) zoom_ = 45.0;
// }

// calculates the front vector from the CameraPack's (updated) Euler Angles
void CameraPack::UpdateCameraVectors() {
  // calculate the new Front vector
  glm::vec3 front;
  front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  front.y = sin(glm::radians(pitch_));
  front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  front_ = glm::normalize(front);
  // also re-calculate the Right and Up vector
  right_ = glm::normalize(glm::cross(
      front_, world_up_));  // normalize the vectors, because their length gets
                            // closer to 0 the more you look up or down which
                            // results in slower movement.
  up_ = glm::normalize(glm::cross(right_, front_));
}

};  // namespace kuro
