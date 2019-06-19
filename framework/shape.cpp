#include <shape.hpp>

Shape::Shape(std::string const& name, Color const& color) : name_{name}, color_{color}  {}

Shape::Shape() : name_{"Hilbert"}, color_{Color{0,0,0}}  {}