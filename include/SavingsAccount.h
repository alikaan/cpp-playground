#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
    private:
        double interest_rate;
    public:
        SavingsAccount(const std::string& owner, double initial_balance, double interest_rate);
        ~SavingsAccount();
        
        void apply_interest();
        void printInfo() const override;
};