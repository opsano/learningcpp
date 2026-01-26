#pragma once
#include <iomanip>
#include <iostream>
/*
 * account is a class, thus variables are initialized as private (unlike a struct).
 * this class allows us to create account objects and contains functions which allow for manipulation of account data.
 */
class Account
{
    // two private variables for our account
    double balance_;
    double rate_;

public:
    Account()
    {
        // constructor for a base account
        std::cout << std::fixed << std::setprecision(2); // this allows us to set our double to have two decimal places
        balance_ = 100.00;
        rate_ = 0.03;
    }

    Account(double balance, double rate)
    {
        // overloaded constructor which allows us to set base rate and balance
        std::cout << std::fixed << std::setprecision(2);
        balance_ = balance;
        rate_ = rate;
    }

    void displayBalance()
    {
        std::cout << "Your Balance: " << balance_ << "\n";
    }

    void displayRate()
    {
        std::cout << "Your Rate: " << rate_ << "\n";
    }

    bool deposit(double depositAmount)
    {
        if (depositAmount <= 0)
        {
            std::cout << "sorry, you can only deposit positive amounts\n";
            return false;
        }
        balance_ += depositAmount;
        return true;
    }

    bool withdraw(const double withdrawAmount)
    {
        if (withdrawAmount <= 0)
        {
            std::cout << "sorry, you can't withdraw negaitve amounts\n";
            return false;
        }
        if (withdrawAmount > balance_)
        {
            std::cout << "sorry, you can't withdraw more than you currently have\n";
            return false;
        }
        balance_ -= withdrawAmount;
        return true;
    }

    bool accrueInterest(const int months)
    {
        if (months <= 0)
        {
            std::cout << "sorry, you can't accrue negative months of interest\n";
            return false;
        }
        const double interest = balance_ * rate_ * months;
        balance_ += interest;
        std::cout << "your interest: " << interest << "\n";
        return true;
    }
};
