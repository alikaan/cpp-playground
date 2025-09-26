#pragma once

#include <iostream>
#include "IShape.h"

class Circle : public IShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle\n";
    }

    double area() const override {
        return 3.14 * radius * radius;
    }
    ~Circle() override {
        std::cout << "Destroying Circle object\n";
    }
};