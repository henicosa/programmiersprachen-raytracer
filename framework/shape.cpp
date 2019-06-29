#include <shape.hpp>

Shape::Shape(std::string const& name, Color const& color) : name_{name}, color_{color}  {}

Shape::Shape() : name_{"Hilbert"}, color_{Color{0,0,0}}  {}

std::ostream& Shape::print(std::ostream& os) const {
  os << "Mein name ist " <<  name_ << " und ich habe die Farbe " << color_ << ". ";
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
  s.print(os);
  return os;
};
