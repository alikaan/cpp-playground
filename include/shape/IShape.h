#pragma once

class IShape {
public:
    virtual void draw() const = 0;        // Pure virtual
    virtual double area() const = 0;      // Pure virtual
    virtual ~IShape() {}                  // Always add virtual destructor
};