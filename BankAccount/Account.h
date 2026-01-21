#pragma once
#include <iomanip>
#include <iostream>
class Account
{

    double _balance;
    double _rate;

public:
    Account() {
        std::cout << std::fixed << std::setprecision(2);
        _balance = 100.00;
        _rate = 0.03;
    }
    Account(double balance, double rate) {
        std::cout << std::fixed << std::setprecision(2);
        _balance = balance;
        _rate = rate;
    }

    void displayBalance() {
        std::cout << "Your Balance: " << _balance <<"\n";
    }

    void displayRate() {
        std::cout << "Your Rate: " << _rate << "\n";
    }

    bool deposit(double depositAmount) {
        if (depositAmount <= 0) {
            std::cout << "sorry, you can only deposit positive amounts\n";
            return false;
        }
        _balance += depositAmount;
        return true;
    }

    bool withdraw(double withdrawAmount) {
        if (withdrawAmount <= 0) {
            std::cout << "sorry, you can't withdraw negaitve amounts\n";
            return false;
        }
        else if (withdrawAmount > _balance) {
            std::cout << "sorry, you can't withdraw more than you currently have\n";
            return false;
        }
        _balance -= withdrawAmount;
        return true;
    }

    bool accrueInterest(int months) {
        if (months <= 0) {
            std::cout << "sorry, you can't accrue negative months of interest\n";
            return false;
        }
        double interest = _balance * _rate * months;
        _balance += interest;

        std::cout << "your interest: " << interest << "\n";
        return true;
    }

};

