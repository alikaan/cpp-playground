#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

/*
[ captures ] ( parameters ) -> return_type {
    function body
}
*/

class LambdaExamples {
public:
    static void basicLambda() {
        auto greet = []() {
            std::cout << "Hello from lambda!\n";
        };
        greet();
    }

    static void lambdaWithParams() {
        auto add = [](int a, int b) -> int {
            return a + b;
        };
        std::cout << "2 + 3 = " << add(2, 3) << "\n";
    }

    static void captureByValue() {
        int x = 10;
        auto showX = [x]() {
            std::cout << "Captured x by value: " << x << "\n";
        };
        showX();
    }

    static void captureByReference() {
        int y = 5;
        auto modifyY = [&y]() {
            y += 10;
        };
        modifyY();
        std::cout << "Modified y by reference: " << y << "\n";
    }

    static void allByValue() {
        int a = 1, b = 2;
        auto byValue = [=]() {
            std::cout << "Captured all by value: a = " << a << ", b = " << b << "\n";
        };
        byValue();
    }

    static void allByReference() {
        int a = 1, b = 2;
        auto byReference = [&]() {
            std::cout << "Captured all by reference: a = " << a << ", b = " << b << "\n";
        };
        byReference();
    }

    // By default, variables captured by value in lambdas are const.
    // Adding `mutable` allows the lambda to modify its own copy of those values.
    // Note: This does NOT affect the original variable outside the lambda.
    static void mutableLambda() {
        int count = 0;
        auto increment = [count]() mutable {
            count++;
            std::cout << "Inside mutable lambda, count: " << count << "\n";
        };
        increment();
        std::cout << "Outside, original count is still: " << count << "\n";
    }

    static void lambdaInSTL() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::cout << "Numbers: ";
        std::for_each(numbers.begin(), numbers.end(), [](int n) {
            std::cout << n << " ";
        });
        std::cout << "\n";
    }

    static void initCapture() {
        auto initAtFirst = [z = 42]() {
            std::cout << "Init capture (C++14): z = " << z << "\n";
        };
        initAtFirst();
    }

    static void runAll() {
        std::cout << "Running Lambda Examples:\n";
        basicLambda();
        lambdaWithParams();
        captureByValue();
        captureByReference();
        allByValue();
        allByReference();
        mutableLambda();
        lambdaInSTL();
        initCapture();
        std::cout << "Finished Lambda Examples.\n\n";
    }   
};