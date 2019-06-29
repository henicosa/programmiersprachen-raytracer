#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <cmath>

class Sphere: public Shape {
  public:
    Sphere();
    Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius);
    virtual float area() const override;
    std::ostream& print(std::ostream& os) const override;
    virtual float volume() const override;

  private:
    glm::vec3 mid_;
    float radius_;

};

#endif // sphere.hpp