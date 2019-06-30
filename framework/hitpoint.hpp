#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>
#include <cmath>
#include "color.hpp"

struct HitPoint {
  bool intersected = false;
  float distance = HUGE_VALF;
  std::string x_name = "No instance"; 
  Color x_color = Color{0.0f, 0.0f, 0.0f};
  glm::vec3 intersection_point = glm::vec3{};
  glm::vec3 intersection_direction = glm::vec3{};
};

#endif // ray.hpp