#pragma once
#include <string>

class BankAccount {
    protected:
        std::string owner;
        double balance;
        mutable int x_mutable; // Example of mutable member variable
    
    public:
        BankAccount(const std::string& owner, double initial_balance);
        virtual ~BankAccount();

        void deposit(double amount);
        bool withdraw(double amount);
        double getBalance() const;
        std::string getOwner() const;
        virtual void printInfo() const;

        friend std::ostream& operator<<(std::ostream& os, const BankAccount& account);
        BankAccount& operator+=(const BankAccount& rhs);
};

bool operator==(const BankAccount& lhs, const BankAccount& rhs);

BankAccount operator+(const BankAccount& lhs, const BankAccount& rhs);

//BankAccount operator+=(BankAccount& lhs, const BankAccount& rhs);