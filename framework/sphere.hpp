#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <cmath>
#include <hitpoint.hpp>
#include <ray.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

class Sphere: public Shape {
  public:
    Sphere();
    Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius);
    float area() const override;
    std::ostream& print(std::ostream& os) const override;
    float volume() const override;
    HitPoint intersect(Ray& ray) const;
    ~Sphere();

  private:
    glm::vec3 mid_;
    float radius_;

};

#endif // sphere.hpp