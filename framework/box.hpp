#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"


class Box: public Shape 
{
    public:

    Box();
    Box(glm::vec3 minimum_, glm::vec3 maximum_);


    double area() const override;
    double volume() const override;

    
    glm::vec3 get_minimum() const; 
    glm::vec3 get_maximum() const;

    private:
    glm::vec3 maximum_;
    glm::vec3 minimum_;

};

#endif