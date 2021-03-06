#ifndef SRC_CORE_ELEMENTS_CAMERA_PACK_H_
#define SRC_CORE_ELEMENTS_CAMERA_PACK_H_

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "src/core/elements/pack.h"

namespace kuro {

// Defines several possible options for camera movement. Used as abstraction to
// stay away from window-system specific input methods
enum CameraMovement { FORWARD, BACKWARD, LEFT, RIGHT };

// Default camera values
const float default_yaw = -90.0;
const float default_pitch = 0.0;
const float default_speed = 2.5;
const float default_sensitivity = 0.1;
const float default_zoom = 45.0;

// An abstract camera class that processes input and calculates the
// corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class CameraPack : public Pack {
 public:
  // camera Attributes
  glm::vec3 front_;
  glm::vec3 up_;
  glm::vec3 right_;
  glm::vec3 world_up_;

  // euler Angles
  float yaw_;
  float pitch_;

  // camera options
  float movement_speed_;
  float mouse_sensitivity_;
  float zoom_;

  float zoom() const { return zoom_; }

  // constructor with vectors
  CameraPack(const glm::vec3 &up = glm::vec3(0.0, 1.0, 0.0),
             const float yaw = default_yaw, const float pitch = default_pitch);

  glm::mat4 GetPerspectiveMatrix(const float ratio);

  // returns the view matrix calculated using Euler Angles and the LookAt Matrix
  glm::mat4 GetViewMatrix(const glm::vec3 &position);

 private:
  // calculates the front vector from the Camera's (updated) Euler Angles
  void UpdateCameraVectors();
};

};  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_CAMERA_PACK_H_
