#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <math.h>
#include <string>
#include <iostream>
#include <glm/gtx/intersect.hpp>

#include "shape.hpp"
#include "color.hpp"
#include "Ray.hpp"




class Sphere: public Shape 
{
    public:
    Sphere(glm::vec3 const& center, double const& radius);
    Sphere(glm::vec3 const& center, double const& radius, std::string const& name, Color const& color);
    ~Sphere();

    double area() const override;  //Flächeninhalt berechnen
    double volume() const override; //Volumen berechnen

    glm::vec3 get_center() const;
    double get_radius() const;

    //Aufgabe 5.4
    std::ostream& print(std::ostream& os) const override;

    //Aufgabe 5.6
    bool intersect (Ray const& ray, float& distance) const;


    private:
    double r_;
    glm::vec3 center_;

};


#endif