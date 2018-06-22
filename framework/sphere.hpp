#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <math.h>

#include "shape.hpp"



class Sphere: public Shape 
{
    public:
    Sphere();
    Sphere(glm::vec3 const& center_, double r_);

    double area() const override;  //Flächeninhalt berechnen
    double volume() const override; //Volumen berechnen

    glm::vec3 get_center() const;
    double get_radius() const;


    private:
    double r_;
    glm::vec3 center_;

};


#endif