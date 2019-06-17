#include "sphere.hpp"

Sphere::Sphere() : Shape(), mid_{glm::vec3{}}, radius_{1} {};

Sphere::Sphere(glm::vec3 const& mid, float radius) : Shape(), mid_{mid}, radius_{radius} {};

float Sphere::area() const {
  return 4 * M_PI * pow(radius_, 2);
}

float Sphere::volume() const {
  return (4.f/3.f) * M_PI * pow(radius_, 3);
}