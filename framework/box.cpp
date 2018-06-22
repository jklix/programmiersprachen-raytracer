#include "box.hpp"

Box::Box(): //Standartkonstruktor
Shape(),
minimum_(50.0,50.0,50.0),
maximum_(100.0, 100.0, 100.0)
{};

//Box::Box(glm::vec3 minimum_, glm::vec3 maximum_):
//minimum_(minimum_),
//maximum_(maximum_)
//{};


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