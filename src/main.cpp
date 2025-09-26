#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <cassert>

#include "shape/Circle.h"
#include "shape/Square.h"

#include "examples/TemplateExamples.h"
#include "examples/LambdaExamples.h"
#include "examples/STLAndMoveExamples.h"
#include "examples/MemoryExamples.h"
#include "examples/PointerExamples.h"

#include "dataStructures/MyString.h"

#include "utils.h"
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "TestThread.h"
#include "Solution.h"
#include "Animal.h"

namespace NamespaceExample {
    void print_hello() {
        std::cout << "Hello from print_hello from NamespaceExample!" << std::endl;
    }
}

int main() {

    seperator();
    NamespaceExample::print_hello();
    seperator();
    Animal* myDog = new Dog("Buddy");
    myDog->speak();

    Animal* myAnimal = new Animal("Generic");
    myAnimal->speak();

    makeSpeak(*myDog);    // Outputs: Dog barks
    makeSpeak(*myAnimal); // Outputs: Animal speaks

    Dog localdog("LocalBuddy");
    makeSpeak(localdog);  // Outputs: Dog barks
    
    seperator();

    std::cout << "Testing hasUniqueCharacters function:" << std::endl;
    bool res = hasUniqueCharacters("world");
    if (res) {
        std::cout << "All characters are unique." << std::endl;
    } else {
        std::cout << "There are duplicate characters." << std::endl;
    }

    assert(hasUniqueCharacters("world") == true);
    assert(hasUniqueCharacters("hello") == false);

    seperator();
    /* This is an example of using unique_ptr
        When the vector goes out of scope, the Circle and Square objects are automatically deleted.
    */
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
    
    seperator();

    LambdaExamples::runAll();

    seperator();

    STLAndMoveExamples::runAll();

    seperator();

    PointerExamples::runAll();

    seperator();
    MemoryExamples::runAll();

    seperator();
    {
        std::string hello = "Hello";
        MyString a(hello);  // Copy constructor
        MyString b(std::move(hello)); // Move constructor
        MyString c("Temporary C String"); 
        MyString d(std::string("Another Temporary String"));
        
        processMyString(a);
        processMyString(b);
        processMyString(c);
        processMyString(d);
        processMyString(MyString("Rvalue Temporary"));
    }
    
    seperator();
    return 0;
    
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


    
    BankAccount merged = account1 + account2;


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


    std::cout << "Max of 3 and 7: " << getMax(3, 7) << std::endl;
    std::cout << "Max of 3.14 and 2.71: " << getMax(3.14, 2.71) << std::endl;
    std::cout << "Max of 'a' and 'z': " << getMax('a', 'z') << std::endl;
    std::cout << "Max of \"apple\" and \"banana\": " << getMax(std::string("apple"), std::string("banana")) << std::endl;

    Box<int> intBox(42);
    Box<std::string> strBox("hello");

    std::cout << "Boxed int: " << intBox.getValue() << std::endl;
    std::cout << "Boxed string: " << strBox.getValue() << std::endl;


    TestThread::runThreadsWithFunction();
    TestThread::runThreadsWithLambda();

    std::cout << std::endl;

    TestThread::runMultipleThreadsInLoop(5);

    std::cout << std::endl;

    auto task = []() {
        std::cout << "Task running in thread." << std::endl;
    };

    std::thread t1(task);     // Start thread t1
    std::thread t2 = std::move(t1); // Move t1 to t2

    std::cout << std::endl;

    if (!t1.joinable())
    {
        std::cout << "t1 is no longer joinable.\n";
    }

    if (t2.joinable())
    {
        std::cout << "t2 is joinable, waiting for it to finish.\n";
        t2.join(); // Valid and safe
    }

    std::cout << std::endl;

    NamespaceExample::print_hello();

    std::cout << std::endl;

    std::string test = "hello world";
    std::cout << "my test variable: " << test << std::endl;
    std::cout << "lengt of test: " << test.size() <<std::endl;
    
    //std::vector<int> nums = {1, 0, 2, 0, 3, 0, 4};
    std::vector<int> nums = {0,0,1};
    std::cout << "Original vector: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";
    Solution::moveZeroesToEnd(nums);
    std::cout << "After moving zeroes to end: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::cout << std::endl;


    std::string reversed = Solution::reverseWords("Hello World from C++");
    std::cout << "Reversed words: " << reversed << std::endl;

    std::cout << std::endl;

    std::cout << "GCD of 'ABABAB' and 'ABAB': " 
              << Solution::gcdOfStrings("ABABAB", "ABAB") << std::endl;

    std::cout << std::endl;

    std::vector<int> bitCounts = Solution().countBits(5);
    std::cout << "Bit counts for numbers 0 to 5: ";
    for (int count : bitCounts) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    Solution::drawReversedPyramid(7);

    std::cout << std::endl;
    return 0;
}