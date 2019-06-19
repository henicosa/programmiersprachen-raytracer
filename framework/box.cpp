#include "box.hpp"

Box::Box() : Shape{}, min_{glm::vec3{}}, max_{glm::vec3{1}}  {
}

Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max) 
: Shape{name, color}, min_{min}, max_{max}  {}

float Box::area() const {
  float x_dim = max_[0] - min_[0];
  float y_dim = max_[1] - min_[1];
  float z_dim = max_[2] - min_[2];
  return 2*(x_dim * y_dim) + 2*(x_dim * z_dim) + 2*(y_dim * z_dim);
}

float Box::volume() const {
  float x_dim = max_[0] - min_[0];
  float y_dim = max_[1] - min_[1];
  float z_dim = max_[2] - min_[2];
  return x_dim * y_dim * z_dim;
}