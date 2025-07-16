#pragma once
#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks\n";
    }
};

void makeSpeak(const Animal& a) {
    a.speak();  // Uses Dog::speak if passed a Dog
}