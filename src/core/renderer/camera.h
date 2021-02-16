#ifndef KURO_CORE_RENDERER_CAMERA_H_
#define KURO_CORE_RENDERER_CAMERA_H_

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

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
class Camera {
 public:
  // camera Attributes
  glm::vec3 position_;
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
  Camera(const glm::vec3 &position = glm::vec3(0.0, 0.0, 0.0),
         const glm::vec3 &up = glm::vec3(0.0, 1.0, 0.0),
         const float yaw = default_yaw, const float pitch = default_pitch);
  // constructor with scalar values
  Camera(const float pos_x, const float pos_y, const float pos_z,
         const float up_x, const float up_y, const float up_z, const float yaw,
         const float pitch);

  // returns the view matrix calculated using Euler Angles and the LookAt Matrix
  glm::mat4 GetViewMatrix();

  // processes input received from any keyboard-like input system. Accepts input
  // parameter in the form of camera defined ENUM (to abstract it from windowing
  // systems)
  void ProcessKeyboard(const CameraMovement direction, const float delta_time);

  // processes input received from a mouse input system. Expects the offset
  // value in both the x and y direction.
  void ProcessMouseMovement(const float x_offset, const float y_offset,
                            GLboolean constrain_pitch = true);

  // processes input received from a mouse scroll-wheel event. Only requires
  // input on the vertical wheel-axis
  void ProcessMouseScroll(const float y_offset);

 private:
  // calculates the front vector from the Camera's (updated) Euler Angles
  void UpdateCameraVectors();
};

};  // namespace kuro

#endif