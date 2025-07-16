#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <utility> // for std::move

class STLAndMoveExamples {
public:
    static void vectorExample() {
        std::vector<int> nums = {1, 2, 3, 4};
        nums.push_back(5);
        std::cout << "Vector elements: ";
        for (int n : nums) std::cout << n << " ";
        std::cout << "\n";
    }

    static void listExample() {
        std::list<std::string> names = {"Ali", "Kaan", "Turkmen"};
        names.push_front("Mr.");
        std::cout << "List elements: ";
        for (const auto& name : names) std::cout << name << " ";
        std::cout << "\n";
    }

    static void mapExample() {
        std::map<std::string, int> ageMap;
        ageMap["Alice"] = 30;
        ageMap["Bob"] = 25;
        std::cout << "Map elements:\n";
        for (const auto& pair : ageMap)
            std::cout << pair.first << ": " << pair.second << "\n";
    }

    static void moveSemanticsExample() {
        std::string a = "Hello";
        std::string b = std::move(a);  // Transfers ownership

        std::cout << "Moved string b: " << b << "\n";
        std::cout << "Original string a (after move): '" << a << "'\n";
    }
    static void runAll() {
        std::cout << "Running STL and Move Semantics Examples:\n";
        vectorExample();
        listExample();
        mapExample();
        moveSemanticsExample();
        std::cout << "All STL and Move Semantics examples completed.\n\n";
    }
};