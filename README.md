# C++ Playground

A comprehensive C++ learning and demonstration project showcasing various C++ concepts, features, and best practices using C++17 standard.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Building and Running](#building-and-running)
- [Code Examples](#code-examples)
- [Prerequisites](#prerequisites)
- [Contributing](#contributing)

## 🎯 Overview

This project serves as a practical learning playground for C++ programming concepts. It demonstrates various C++ features including:

- Object-oriented programming (OOP) principles
- Memory management and smart pointers
- Templates and generic programming
- STL containers and algorithms
- Lambda expressions and functional programming
- Move semantics and rvalue references
- Operator overloading
- Inheritance and polymorphism
- Modern C++ best practices

## ✨ Features

### Core C++ Concepts
- **Classes and Objects**: Bank account system with inheritance
- **Polymorphism**: Shape hierarchy with virtual functions
- **Operator Overloading**: Custom operators for user-defined types
- **Templates**: Generic functions and classes
- **Lambda Expressions**: Various lambda usage patterns
- **Smart Pointers**: Memory management with `unique_ptr`
- **Move Semantics**: Efficient resource management
- **STL Containers**: Vector, algorithms, and iterators

### Practical Examples
- Banking system with account management
- Shape drawing with polymorphism
- String manipulation with custom MyString class
- Template-based generic programming
- Lambda functions for functional programming
- Memory management demonstrations

## 📁 Project Structure

```
cpp-playground/
├── app                 # Compiled executable
├── Makefile           # Build configuration
├── README.md          # This file
├── run.sh             # Build and run script
├── include/           # Header files
│   ├── Animal.h
│   ├── BankAccount.h
│   ├── Circle.h
│   ├── IShape.h
│   ├── LambdaExamples.h
│   ├── MemoryExamples.h
│   ├── MyString.h
│   ├── PointerExamples.h
│   ├── SavingsAccount.h
│   ├── Square.h
│   ├── STLAndMoveExamples.h
│   ├── TemplateExamples.h
│   └── utils.h
└── src/               # Source files
    ├── BankAccount.cpp
    ├── main.cpp
    ├── SavingsAccount.cpp
    └── utils.cpp
```

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: GCC or Clang with C++17 support
- **Make**: Build automation tool
- **macOS/Linux**: Unix-like environment (tested on macOS)

### Installation

1. Clone or download this repository
2. Navigate to the project directory:
   ```bash
   cd cpp-playground
   ```

## 🔨 Building and Running

### Method 1: Using the run script (Recommended)
```bash
chmod +x run.sh
./run.sh
```

### Method 2: Using Make directly
```bash
# Clean previous builds
make clean

# Build the project
make

# Run the executable
./app
```

### Method 3: Manual compilation
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o app
./app
```

## 💻 Code Examples

### Bank Account System
```cpp
BankAccount account1("John Doe", 1000.0);
account1.deposit(500.0);
account1.withdraw(200.0);
```

### Template Functions
```cpp
int maxInt = getMax(5, 10);
double maxDouble = getMax(3.14, 2.71);
string maxString = getMax("apple", "banana");
```

### Lambda Expressions
```cpp
auto greet = []() {
    std::cout << "Hello from lambda!\n";
};
greet();
```

### Smart Pointers
```cpp
std::unique_ptr<SavingsAccount> savings = 
    std::make_unique<SavingsAccount>("Savings", 2000.0, 3.0);
savings->apply_interest();
// Automatically cleaned up when out of scope
```

### Move Semantics
```cpp
std::string hello = "Hello";
MyString a(hello);              // Copy constructor
MyString b(std::move(hello));   // Move constructor
```

## 🎓 Learning Objectives

This project helps you understand:

1. **Memory Management**: Stack vs heap allocation, RAII principles
2. **Object-Oriented Design**: Encapsulation, inheritance, polymorphism
3. **Modern C++ Features**: Smart pointers, move semantics, auto keyword
4. **Template Programming**: Generic functions and classes
5. **STL Usage**: Containers, algorithms, iterators
6. **Best Practices**: Const correctness, exception safety, code organization

## 🤝 Contributing

Feel free to:
- Add new C++ concept demonstrations
- Improve existing code examples
- Add more comprehensive comments
- Suggest better practices
- Report bugs or issues

## 📚 Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [Modern C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [C++17 Features](https://en.cppreference.com/w/cpp/17)

## 📄 License

This project is for educational purposes. Feel free to use and modify as needed.

---

**Happy Coding!** 🚀