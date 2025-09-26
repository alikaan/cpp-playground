#pragma once
#include <iostream>
#include <cstring>

// Generic function to find maximum of two values
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <>
const char* getMax<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// Class template example

template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() const {
        return value;
    }
    void setValue(T val) {
        value = val;
    }
};
