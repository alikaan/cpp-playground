#pragma once

#include <iostream>
#include "IShape.h"

class Square : public IShape {
    private:
        double side_length;
    public:
        Square(double side) : side_length(side) {} ;

        void draw() const override {
            std::cout << "Drawing a square with side length: " << side_length << "\n";
        }

        double area() const override {
            std::cout << "Area of square: " << side_length * side_length << "\n";
            return side_length * side_length;
        }
        ~Square() override {
            std::cout << "Destroying Square object\n";
        }
};

