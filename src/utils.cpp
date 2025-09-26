#include <iostream>
#include "utils.h"
#include <set>

void print_hello() {
    std::cout << "Utils says hello!" << std::endl;
}

void seperator() {
    std::cout << std::endl << "************************************" << std::endl;
}

bool hasUniqueCharacters(const std::string& str) {
    std::set<char> charSet;
    for (char c : str) {
        if (charSet.find(c) != charSet.end()) {
            return false; // Duplicate character found
        }
        charSet.insert(c);
    }
    return true; // All characters are unique
}

ListNode* buildList(std::initializer_list<int> vals){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int v : vals){
        ListNode* node = new ListNode(v);
        if(!head){
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

std::vector<int> listToVector(ListNode* head){
    std::vector<int> result;
    while(head){
        result.push_back(head->value);
        head = head->next;
    }
    return result;
}

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}