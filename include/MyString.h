#include <iostream>
#include <string>

class MyString {
private:
    std::string data;
    char* buffer;

public:
    // Default constructor
    
    MyString(const char* str = "") : data(str) {
        buffer = new char[data.size() + 1];
        std::copy(data.begin(), data.end(), buffer);
        buffer[data.size()] = '\0'; // Null-terminate the buffer
        std::cout << "Constructed with default: " << data << "\n";
    }
    // Copy Constructor
    MyString(const std::string& str) : data(str) {
        buffer = new char[data.size() + 1];
        std::copy(data.begin(), data.end(), buffer);
        buffer[data.size()] = '\0'; // Null-terminate the buffer
        std::cout << "Constructed with copy: " << data << "\n";
    }

    // Move constructor
    MyString(std::string&& str) : data(std::move(str)) {
        std::cout << "Constructed with move: " << data << "\n";
    }

    void print() const {
        std::cout << "MyString holds: " << data << "\n";
    }

    // Destructor
    ~MyString() {
        delete[] buffer; // Free the dynamically allocated buffer
        std::cout << "Destructor called for: " << data << "\n";
    }
};

// Overload to accept lvalue
void processMyString(MyString& s) {
    std::cout << "process(MyString&): Lvalue reference\n";
    s.print();
}

// Overload to accept rvalue
void processMyString(MyString&& s) {
    std::cout << "process(MyString&&): Rvalue reference\n";
    s.print();
}