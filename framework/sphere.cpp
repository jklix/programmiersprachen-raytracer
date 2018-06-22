#include "sphere.hpp"


Sphere::Sphere():
center_(50,50,50),
r_(100)
{};

Sphere::Sphere(glm::vec3 const& center_, double r_):
Shape(),
center_(center_),
r_(r_)
{}

double Sphere::area() const
{
    return 4 * M_PI * (r_ * r_);
}

double Sphere::volume() const
{
    return (4/3) * M_PI * (r_ * r_ * r_);
}

glm::vec3 Sphere::get_center() const
{
    return center_;
}

double Sphere::get_radius() const
{
    return r_;
}





