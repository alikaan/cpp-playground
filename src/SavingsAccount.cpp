#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string& owner, double initial_balance, double interest_rate)
    : BankAccount(owner, initial_balance), interest_rate(interest_rate) {
        std::cout << "Savings Account created for: " << owner 
                  << " with interest rate: " << interest_rate
                  << std::endl;
        if (interest_rate < 0) {
            std::cerr << "Warning: Negative interest rate!" << std::endl;
            this->interest_rate = 0; // Set to zero if negative
        }
    }
SavingsAccount::~SavingsAccount() {
    std::cout << "SavingsAccount destructor called for: " << owner << std::endl;
}

void SavingsAccount::apply_interest() {
    double interest = getBalance() * interest_rate / 100;
    deposit(interest);
    std::cout << "Applied interest: " << interest << ", New Balance: " << getBalance() << std::endl;
}

void SavingsAccount::printInfo() const {
    BankAccount::printInfo(); // Call base class printInfo
    std::cout << "Savings Account Owner: " << owner 
              << ", Balance: " << balance 
              << std::endl;
    std::cout << "Interest Rate: " << interest_rate << "%" << std::endl;
}