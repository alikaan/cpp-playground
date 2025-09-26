#pragma once
#include <iostream>
#include <memory>  // For smart pointers

class MemoryExamples {
public:
    // 1. Using unique_ptr with single object
    static void uniquePtrExample() {
        std::unique_ptr<int> ptr = std::make_unique<int>(42);
        std::cout << "Unique ptr points to: " << *ptr << "\n";
    }

    // 2. Using shared_ptr with multiple owners
    static void sharedPtrExample() {
        std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
        std::shared_ptr<int> ptr2 = ptr1;  // Shared ownership

        std::cout << "Shared ptr use count: " << ptr1.use_count() << "\n";
        std::cout << "Value: " << *ptr1 << "\n";
    }

    // 3. Using unique_ptr with dynamic array
    static void uniquePtrArrayExample() {
        std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
        for (int i = 0; i < 5; ++i) {
            arr[i] = i * 10;
        }

        std::cout << "Dynamic array: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    // 4. Passing reference to a function
    static void modifyByReference(int& ref) {
        ref *= 2;
    }

    static void referenceExample() {
        int x = 7;
        std::cout << "Before: " << x << "\n";
        modifyByReference(x);
        std::cout << "After: " << x << "\n";
    }

    // 5. Shared pointer ownership tracking
    static void sharedPtrOwnershipExample() {
        std::shared_ptr<int> a = std::make_shared<int>(55);
        std::cout << "[A created] Value: " << *a << ", use_count: " << a.use_count() << "\n";

        {
            std::shared_ptr<int> b = a;
            std::cout << "[B copied from A] use_count: " << b.use_count() << "\n";

            {
                std::shared_ptr<int> c = b;
                std::cout << "[C copied from B] use_count: " << c.use_count() << "\n";
            } // c destroyed
            std::cout << "[C destroyed] use_count: " << b.use_count() << "\n";
        } // b destroyed

        std::cout << "[B destroyed] use_count: " << a.use_count() << "\n";
    } // a destroyed} // a goes out of scope, object is deleted

    static void runAll() {
        std::cout << "\n=== Smart Pointer Examples ===\n";
        uniquePtrExample();
        sharedPtrExample();

        std::cout << "\n=== Dynamic Array Example ===\n";
        uniquePtrArrayExample();

        std::cout << "\n=== Reference Example ===\n";
        referenceExample();
        std::cout << "\n=== Shared Pointer Ownership Example ===\n";
        sharedPtrOwnershipExample();
        std::cout << "\n";
    }
};