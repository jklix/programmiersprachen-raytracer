#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>


class Shape 
{
    public:
    Shape();

    virtual double area() const = 0;
    virtual double volume() const = 0;

    
};

#endif