#pragma once
#include <iomanip>
#include <iostream>
class Account
{

    double balance_;
    double rate_;

public:
    Account() {
        std::cout << std::fixed << std::setprecision(2);
        balance_ = 100.00;
        rate_ = 0.03;
    }
    Account(double balance, double rate) {
        std::cout << std::fixed << std::setprecision(2);
        balance_ = balance;
        rate_ = rate;
    }

    void displayBalance() {
        std::cout << "Your Balance: " << balance_ <<"\n";
    }

    void displayRate() {
        std::cout << "Your Rate: " << rate_ << "\n";
    }

    bool deposit(double depositAmount) {
        if (depositAmount <= 0) {
            std::cout << "sorry, you can only deposit positive amounts\n";
            return false;
        }
        balance_ += depositAmount;
        return true;
    }

    bool withdraw(const double withdrawAmount) {
        if (withdrawAmount <= 0) {
            std::cout << "sorry, you can't withdraw negaitve amounts\n";
            return false;
        }
        else if (withdrawAmount > balance_) {
            std::cout << "sorry, you can't withdraw more than you currently have\n";
            return false;
        }
        balance_ -= withdrawAmount;
        return true;
    }

    bool accrueInterest(const int months) {
        if (months <= 0) {
            std::cout << "sorry, you can't accrue negative months of interest\n";
            return false;
        }
        const double interest = balance_ * rate_ * months;
        balance_ += interest;

        std::cout << "your interest: " << interest << "\n";
        return true;
    }

};

