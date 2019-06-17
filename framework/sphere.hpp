#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <cmath>

class Sphere: public Shape {
  public:
    Sphere();
    Sphere(glm::vec3 const& mid, float radius);
    virtual float area() const override;
    virtual float volume() const override;

  private:
    glm::vec3 mid_;
    float radius_;

};

#endif // sphere.hpp