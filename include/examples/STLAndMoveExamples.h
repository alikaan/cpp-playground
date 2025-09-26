#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
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

    static void unorderedMapExample() {
        std::unordered_map<std::string, int> ageMap;
        ageMap["Alice"] = 30;
        ageMap["Bob"] = 25;
        std::cout << "Unordered Map elements:\n";
        for (const auto& pair : ageMap)
            std::cout << pair.first << ": " << pair.second << "\n";
    }

    static void setExample() {
        std::set<int> uniqueNumbers = {1, 2, 3, 4, 5};
        uniqueNumbers.insert(3); // Duplicate, won't be added
        std::cout << "Set elements: ";
        for (int n : uniqueNumbers) std::cout << n << " ";
        std::cout << "\n";
    }

    static void queueExample() {
        std::queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        std::cout << "Queue elements: ";
        while (!q.empty()) {
            std::cout << q.front() << " ";
            q.pop();
        }
        std::cout << "\n";
    }

    static void stackExample() {
        std::stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        std::cout << "Stack elements: ";
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << "\n";
    }

    static void moveSemanticsExample() {
        std::string a = "Hello";
        std::string b = std::move(a);  // Transfers ownership

        std::cout << "Moved string b: " << b << "\n";
        std::cout << "Original string a (after move): '" << a << "'\n";
    }
    static void runAll() {
        std::cout << "===STL and Move Semantics Examples===\n";
        vectorExample();
        listExample();
        mapExample();
        unorderedMapExample();
        setExample();
        queueExample();
        stackExample();
        moveSemanticsExample();
    }
};