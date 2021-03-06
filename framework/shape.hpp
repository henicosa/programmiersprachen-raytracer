#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

class Shape {
  public:
    Shape();
    Shape(std::string const& name, Color const& color);
    virtual float area() const = 0;
    virtual float volume() const = 0;
    virtual std::ostream& print(std::ostream& os) const;
    ~Shape(); 

  protected:
    std::string name_;
    Color color_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif // shape.hpp