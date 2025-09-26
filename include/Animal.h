#pragma once
#include <iostream>

class Animal {
    protected:
        std::string name;
    public:
        Animal(const std::string& name = "Animal") : name(name) {}
        virtual void speak() const {
            std::cout << "Animal with a name " << name  << " speaks\n";
        }
};

class Dog : public Animal {
public:
    Dog(const std::string& name = "Dog") : Animal(name) {}
    void speak() const override {
        std::cout << "Dog with a name " << name << " barks\n";
    }
};

void makeSpeak(const Animal& a) {
    a.speak();  // Uses Dog::speak if passed a Dog
}