#pragma once

#include "Vector2D.h"

class Shape {
protected:
    Vector2D center;
    double area;

public:
    Shape() : center(0, 0), area(0) {}
    Shape(Vector2D center) : center(center), area(0) {}

    Vector2D getCenter() const { return center; }
    double getArea() const { return area; }
};
