#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount(const std::string& owner, double initial_balance)
    : owner(owner), balance(initial_balance) 
    {
        //std::cout << "Address of this object: " << this << std::endl;
        void* stack_ptr = __builtin_frame_address(0); //GCC/Clang only
        //std::cout << "Address of stack frame: " << stack_ptr << std::endl;
        if(this > stack_ptr) {
            std::cout << "This object is on the stack." << std::endl;
        } else {
            std::cout << "This object is on the heap." << std::endl;
        }

        std::cout << "Account created for: " << owner 
                  << " with initial balance: " << balance 
                  << std::endl;

        if (balance < 0) {
            std::cerr << "Warning: Negative initial balance!" << std::endl;
            balance = 0;
        }
    }

BankAccount::~BankAccount() {
    std::cout << "BankAccount destructor called for: " << owner << std::endl;
    // No dynamic memory to free in this class, but if there were, we would do so here.
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
    } else {
        std::cout << "Deposit amount must be positive." << std::endl;
    }
} 

bool BankAccount::withdraw(double amount) {
    if(amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawn: " << amount << ", New Balance: " << balance << std::endl;
        return true;
    } else {
        std::cout << "Insufficient funds for withdrawal." << std::endl;
        return false;
    }
}

void BankAccount::printInfo() const {
    x_mutable++; // We can modify mutable member variables even in const member functions
    std::cout << "Bank Account Owner: " << owner << ", Balance: " << balance << std::endl;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getOwner() const{
    return owner;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Bank Account Owner: " << account.owner 
       << ", Balance: " << account.balance;
    return os;
}

bool operator==(const BankAccount& lhs, const BankAccount& rhs) {
    return (lhs.getOwner() == rhs.getOwner() && 
                lhs.getBalance() == rhs.getBalance());
}

BankAccount operator+(const BankAccount& lhs, const BankAccount& rhs) {
    return BankAccount(lhs.getOwner() + " & " + rhs.getOwner(), 
                       lhs.getBalance() + rhs.getBalance());
}

BankAccount& BankAccount::operator+=(const BankAccount& rhs) {
    this->deposit(rhs.getBalance());
    return *this;
}