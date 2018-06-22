#include "shape.hpp"
#include "color.hpp"
#include <iostream>
#include <string>

Shape::Shape():
name_{"Standardname"},
color_{Color{0.0f, 0.0f, 0.0f}}
{};

Shape::Shape(std::string const& name, Color const& color):
name_{name},
color_{color}
{};

Shape::~Shape()
{};

std::string Shape::get_name() const
{
    return name_;
}

Color Shape::get_color() const
{
    return color_;
}