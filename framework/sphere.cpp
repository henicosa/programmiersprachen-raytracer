#include "sphere.hpp"

Sphere::Sphere() : Shape(), mid_{glm::vec3{}}, radius_{1} {};

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius) 
: Shape{name, color}, mid_{mid}, radius_{radius} {};

float Sphere::area() const {
  return 4 * M_PI * pow(radius_, 2);
}

float Sphere::volume() const {
  return (4.f/3.f) * M_PI * pow(radius_, 3);
}

std::ostream& Sphere::print(std::ostream& os) const {
  Shape::print(os);
  os << "Ich bin eine Sphäre.\n";
  return os;
};

HitPoint Sphere::intersect(Ray& ray) const {
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray.origin, ray.direction, 
    mid_, radius_*radius_, distance);
  if (result) {
    glm::vec3 point = ray.origin + ray.direction*distance;
    return HitPoint{
      result, distance, 
      Shape::name_, Shape::color_, 
      point, ray.direction};
  } else {
    return HitPoint{};
  }
}

Sphere::~Sphere() {
  std::cout << "Sphere deconstruction " << name_ << "\n";
}