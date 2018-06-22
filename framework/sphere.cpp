#include "sphere.hpp"


Sphere::Sphere(glm::vec3 const& center, double const& radius):
Shape(),
center_(center),
r_(radius)
{};

Sphere::Sphere(glm::vec3 const& center, double const& radius, std::string const& name, Color const& color):
Shape(name, color),
center_(center),
r_(radius)
{};

Sphere::~Sphere()
{}

double Sphere::area() const
{
    return 4 * M_PI * pow(get_radius(), 2);
}

double Sphere::volume() const
{
    return (4.0/3.0) * M_PI * pow(get_radius(), 3);
}

glm::vec3 Sphere::get_center() const
{
    return center_;
}

double Sphere::get_radius() const
{
    return r_;
}

std::ostream& Sphere::print(std::ostream& os) const
{
    Shape::print(os);
    os << "Area: " << area() << ", \n";
    os << "Volume: " << volume() << ", \n";
    os << "Center: ("<< center_.x << ", " << center_.y << ", " << center_.z << "), \n";
    os << "Radius:" << r_ << ", \n";
    return os;
}




