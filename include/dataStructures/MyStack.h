#include <vector>
#include <iostream>
#include <string>

template <typename T>
class MyStack {
    private:
    std::vector<T> data;
    public:
    void push(const T& val){
        data.push_back(val);
    }
    T pop(){
        if(!data.empty()){
            T val = data.back();
            data.pop_back();
            return val;
        }
        throw std::out_of_range("Stack is empty");
    }
    T top(){
        if(!data.empty()){
            return data.back();
        }
        throw std::out_of_range("Stack is empty");
    }

    // ✅ Overload += operator to push
    MyStack<T>& operator+=(const T& value) {
        push(value);
        return *this;
    }

    bool empty const(){
        return data.empty;
    }
    size_t size const(){
        return data.size;
    }
};
    