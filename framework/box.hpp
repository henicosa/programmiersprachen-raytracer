#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box: public Shape {
  public:
    Box();
    Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
    virtual float area() const override;
    virtual float volume() const override;

  private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif // box.hpp