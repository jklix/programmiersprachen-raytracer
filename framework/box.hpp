#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <string>
#include "color.hpp"
#include <iostream>


class Box: public Shape 
{
    public:

    Box(glm::vec3 const& minimum, glm::vec3 const& maximum);
    Box(glm::vec3 const& minimum, glm::vec3 const& maximum, std::string const& name, Color const& color);


    double area() const override;
    double volume() const override;

    
    glm::vec3 get_minimum() const; 
    glm::vec3 get_maximum() const;

    private:
    glm::vec3 maximum_;
    glm::vec3 minimum_;

};

#endif