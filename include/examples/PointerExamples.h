#pragma once
#include <iostream>

class PointerExamples {
public:
    // 1. Increment using pointer
    static void incrementWithPointer(int* p) {
        if (p) (*p)++;
    }

    // 2. Increment using reference
    static void incrementWithReference(int& ref) {
        ref++;
    }

    // 3. Allocate memory using pointer to pointer
    static void allocateWithDoublePointer(int** ptr) {
        if (ptr) *ptr = new int(42);
    }

    // 4. Allocate memory using reference to pointer
    static void allocateWithReferenceToPointer(int*& p) {
        p = new int(99);
    }

    // 5. Pointer to const value (you can't modify the value)
    static void pointerToConstValue(const int* p) {
        std::cout << "Value (const int*): " << *p << "\n";
        // *p = 10; // ❌ Not allowed
    }

    // 6. Const pointer to value (you can't reassign the pointer)
    static void constPointerToValue() {
        int a = 20;
        int* const p = &a;  // Must initialize
        *p = 30;  // ✅ You can modify the value
        std::cout << "Value (int* const): " << *p << "\n";
        // int b = 40;
        // p = &b; // ❌ Not allowed
    }

    // 7. Const pointer to const value (neither pointer nor value is mutable)
    static void constPointerToConstValue() {
        int a = 50;
        const int* const p = &a;
        std::cout << "Value (const int* const): " << *p << "\n";
        // *p = 60; // ❌ Not allowed
        // int b = 70;
        // p = &b; // ❌ Not allowed
    }

    // Test all in one place
    static void runAll() {
        std::cout << "=== Pointer and Reference Examples ===\n";

        int a = 10;
        incrementWithPointer(&a);
        std::cout << "After incrementWithPointer: " << a << "\n";

        incrementWithReference(a);
        std::cout << "After incrementWithReference: " << a << "\n";

        int* ptr1 = nullptr;
        allocateWithDoublePointer(&ptr1);
        std::cout << "Value from allocateWithDoublePointer: " << *ptr1 << "\n";
        delete ptr1;

        int* ptr2 = nullptr;
        allocateWithReferenceToPointer(ptr2);
        std::cout << "Value from allocateWithReferenceToPointer: " << *ptr2 << "\n";
        delete ptr2;

        pointerToConstValue(&a);
        constPointerToValue();
        constPointerToConstValue();

    }
};