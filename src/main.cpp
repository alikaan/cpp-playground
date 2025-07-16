#include <iostream>
#include <vector>
#include <memory>

#include "utils.h"
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "PointerExamples.h"
#include "MemoryExamples.h"
#include "Circle.h"
#include "Square.h"
#include "TemplateExamples.h"
#include "LambdaExamples.h"
#include "STLAndMoveExamples.h"
#include "MyString.h"

int main() {
    std::cout << "Hello from main!" << std::endl;
    print_hello();
    std::cout << "This project uses C++17 standard." << std::endl;    
    std::cout << std::endl;

    BankAccount account1("account", 350.0);
    account1.deposit(800.0);

    std::cout << "***Test << operator overloading***" 
              << std::endl
              << account1 
              << std::endl;

    std::cout << std::endl;

    BankAccount account2("account", 250.0);
    account2.deposit(700.0);

    std::cout << "***Test << operator overloading***" 
              << std::endl
              << account2 
              << std::endl;

    std::cout << std::endl;

    if(account1 == account2) {
        std::cout << "Both accounts are equal." << std::endl;
    } else {
        std::cout << "Accounts are not equal." << std::endl;
    }

    std::cout << std::endl;

    BankAccount merged = account1 + account2;

    std::cout << std::endl;

    account1 += account2;

    std::cout << "***Test << operator overloading***" 
              << std::endl
              << account1 
              << std::endl;

    std::cout << std::endl;

    SavingsAccount* savings =  new SavingsAccount("Savings", 1000.0, 5.0);
    savings->apply_interest();
    
    delete savings; // Clean up dynamically allocated memory
    std::cout << "Savings account deleted." << std::endl;
    std::cout << std::endl;

    {
        std::unique_ptr<SavingsAccount> smart_savings = std::make_unique<SavingsAccount>("Smart Savings", 2000.0, 3.0);
        smart_savings->apply_interest();
    }
    std::cout << "**Smart savings account is automatically deleted after leaving the scope**" << std::endl;

    std::cout << std::endl;
    PointerExamples::runAll();
    MemoryExamples::runAll();
    std::cout << std::endl;

    {
        std::vector<std::unique_ptr<IShape>> shapes;
        shapes.push_back(std::make_unique<Circle>(5.0));
        shapes.push_back(std::make_unique<Square>(4.0));
        for (const auto& shape : shapes) {
            shape->draw();
            std::cout << "Area: " << shape->area() << std::endl;
        }
    }
    std::cout << "Shapes are automatically deleted when going out of scope." << std::endl;  
    std::cout << std::endl;

    std::cout << "Max of 3 and 7: " << getMax(3, 7) << std::endl;
    std::cout << "Max of 3.14 and 2.71: " << getMax(3.14, 2.71) << std::endl;
    std::cout << "Max of 'a' and 'z': " << getMax('a', 'z') << std::endl;
    std::cout << "Max of \"apple\" and \"banana\": " << getMax(std::string("apple"), std::string("banana")) << std::endl;

    Box<int> intBox(42);
    Box<std::string> strBox("hello");

    std::cout << "Boxed int: " << intBox.getValue() << std::endl;
    std::cout << "Boxed string: " << strBox.getValue() << std::endl;

    std::cout << std::endl;

    LambdaExamples::runAll();

    STLAndMoveExamples::runAll();

    std::string hello = "Hello";
    MyString a(hello);  // Copy constructor
    MyString b(std::move(hello)); // Move constructor
    MyString c("Temporary C String"); 
    MyString d(std::string("Another Temporary String"));
    processMyString(a);
    processMyString(b);
    processMyString(c);
    processMyString(d);

    std::cout << std::endl;

    return 0;
}