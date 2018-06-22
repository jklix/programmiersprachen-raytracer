#include "box.hpp"

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum): 
Shape(),
minimum_(minimum),
maximum_(maximum)
{};

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum, std::string const& name, Color const& color): 
Shape(name, color),
minimum_(minimum),
maximum_(maximum)
{};



//Aufgabe 5.2
double Box::area() const
{
    double a {maximum_.x - minimum_.x};
    double b {maximum_.y - minimum_.y};
    double c {maximum_.z - minimum_.z};

    return 2*a*b + 2*a*c + 2*b*c;
}

double Box::volume() const
{
    double a = maximum_.x - minimum_.x;
    double b = maximum_.y - minimum_.y;
    double c = maximum_.z - minimum_.z;

    return a*b*c;
}

glm::vec3 Box::get_minimum() const
{
    return minimum_;
}

glm::vec3 Box::get_maximum() const
{
    return maximum_;
}

std::ostream& Box::print(std::ostream& os) const
{
    Shape::print(os);
    os << "Area: " << area() << ", \n";
    os << "Volume: " << volume() << ", \n";
    os << "Minimum: ("<<minimum_.x << ", " << minimum_.y << ", " << minimum_.z << "), \n";
    os << "Maximum: ("<<maximum_.x << ", " << maximum_.y << ", " << maximum_.z << "), \n";
    return os;
}