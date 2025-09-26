#pragma once
#include <vector>

template <typename T>
class MyQueue {
private:
    std::vector<T> data;
    size_t frontIndex = 0;

public:
    void push(const T& val) {
        data.push_back(val);
    }

    T pop() {
        if (!empty()) {
            T val = data[frontIndex];
            ++frontIndex;
            return val;
        }
        throw std::out_of_range("Queue is empty");
    }

    T front() const {
        if (!empty()) {
            return data[frontIndex];
        }
        throw std::out_of_range("Queue is empty");
    }

    bool empty() const {
        return frontIndex >= data.size();
    }

    size_t size() const {
        return data.size() - frontIndex;
    }
};