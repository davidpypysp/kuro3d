#include "src/core/renderer/camera.h"

namespace kuro {

// constructor with vectors
Camera::Camera(const glm::vec3 &position, const glm::vec3 &up, const float yaw,
               const float pitch)
    : front_(glm::vec3(0.0, 0.0, -1.0)),
      movement_speed_(default_speed),
      mouse_sensitivity_(default_sensitivity),
      zoom_(default_zoom) {
  position_ = position;
  world_up_ = up;
  yaw_ = yaw;
  pitch_ = pitch;
  UpdateCameraVectors();
}

// constructor with scalar values
Camera::Camera(const float pos_x, const float pos_y, const float pos_z,
               const float up_x, const float up_y, const float up_z,
               const float yaw, const float pitch)
    : front_(glm::vec3(0.0, 0.0, -1.0)),
      movement_speed_(default_speed),
      mouse_sensitivity_(default_sensitivity),
      zoom_(default_zoom) {
  position_ = glm::vec3(pos_x, pos_y, pos_z);
  world_up_ = glm::vec3(up_x, up_y, up_z);
  yaw_ = yaw;
  pitch_ = pitch;
  UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(position_, position_ + front_, up_);
}

// processes input received from any keyboard-like input system. Accepts input
// parameter in the form of camera defined ENUM (to abstract it from windowing
// systems)
void Camera::ProcessKeyboard(const CameraMovement direction,
                             const float delta_time) {
  float velocity = movement_speed_ * delta_time;
  if (direction == FORWARD) position_ += front_ * velocity;
  if (direction == BACKWARD) position_ -= front_ * velocity;
  if (direction == LEFT) position_ -= right_ * velocity;
  if (direction == RIGHT) position_ += right_ * velocity;
}

// processes input received from a mouse input system. Expects the offset
// value in both the x and y direction.
void Camera::ProcessMouseMovement(const float x_offset, const float y_offset,
                                  const GLboolean constrain_pitch) {
  yaw_ += x_offset * mouse_sensitivity_;
  pitch_ += y_offset * mouse_sensitivity_;

  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (constrain_pitch) {
    if (pitch_ > 89.0f) pitch_ = 89.0;
    if (pitch_ < -89.0) pitch_ = -89.0;
  }

  // update Front, Right and Up Vectors using the updated Euler angles
  UpdateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires
// input on the vertical wheel-axis
void Camera::ProcessMouseScroll(const float y_offset) {
  zoom_ -= y_offset;
  if (zoom_ < 1.0) zoom_ = 1.0;
  if (zoom_ > 45.0) zoom_ = 45.0;
}

// calculates the front vector from the Camera's (updated) Euler Angles
void Camera::UpdateCameraVectors() {
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
