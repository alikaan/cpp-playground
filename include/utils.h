#pragma once

void print_hello();
void seperator();
bool hasUniqueCharacters(const std::string& str);

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};