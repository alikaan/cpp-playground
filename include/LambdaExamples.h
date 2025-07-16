#include <iostream>
#include <vector>
#include <algorithm>

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

    static void runAll() {
        std::cout << "Running Lambda Examples:\n";
        basicLambda();
        lambdaWithParams();
        captureByValue();
        captureByReference();
        mutableLambda();
        lambdaInSTL();
        std::cout << "Finished Lambda Examples.\n\n";
    }   
};