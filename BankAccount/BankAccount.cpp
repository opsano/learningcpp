#include <iostream>
#include "account.h"
void printMenu(); // function prototype;
/*
 * validateInputDatatype takes in two arguments, a string reference question, then a reference to a generic variable for stream output.
 * changing our output datatype changes our datatype in our original main function due to it being a reference (out = main variable).
 * we state that our reference to question is const, which just means we promise we won't change the variable, which this function has no
 * reason to do.
 * the function checks if the user's input is correct (i.e., an expected int is actually an int rather than a char)
 * if it's false, we clear the buffer and then return false, otherwise we return true.
 */
template <typename T>
bool validateInputDatatype(const std::string& question, T& out) {
	std::cout << question;
	std::cin >> out;

	if (std::cin.fail() || std::cin.bad())
	{
		// way of resetting input to stop infinite loops
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "invalid input, aborting\n";
		return false;
	}
	return true;
}

int main() {
	// set variables
	bool result;
	int choice = 0;
	Account myAccount(500.00, 2.0);
	
	do {
		printMenu();
		validateInputDatatype("", choice);
		switch (choice) {
			case 1:  // display balance
				myAccount.displayBalance();
				break;
			case 2: // display rate
				myAccount.displayRate();
				break;
			case 3: // deposit
				double depositAmount;
				// validateInputDatatype returns a boolean, but to determine the boolean also runs once through the code
				if (!validateInputDatatype("enter deposit amount: ", depositAmount)){
					/*
					 * we continue here because our data was wrong & thus depositing our deposit amount would be
					 * dubious, instead we continue to allow the user to choose an option again.
					 * this is the same for all other instances of this in withdraw and accrue interest
					 */
					continue; 
				}
				result = myAccount.deposit(depositAmount);
				if (result) {
					std::cout << "deposit successful\n";
					break;
				}
				std::cout << "deposit unsuccessful\n";
				break;
			case 4: // withdraw
				double withdrawAmount;
				if (!validateInputDatatype("enter withdraw amount: ", withdrawAmount)){
					continue;
				}
			
				result = myAccount.withdraw(withdrawAmount);
				if (result) {
					std::cout << "withdraw successful\n";
					break;
				}
				std::cout << "withdraw unsuccessful\n";
				break;
			case 5: // accrue interest
				int months;
				if (!validateInputDatatype("enter number of months to accrue: ", months)){
					continue;
				}
			
				result = myAccount.accrueInterest(months);
				if (result) {
					std::cout << "accural successful\n";
					break;
				}
				std::cout << "accrual unsuccessful\n";
				break;
			case 6: // exit
				std::cout << "bye bye!";
				return 0;
			default:
				std::cout << "please choose an option in the bounds of our menu\n"; 
		}
	} while (choice != 6);
	return 0;
}

// function prints our menu for readability
void printMenu() {
	std::cout << "enter the operation you would like to preform\n";
	std::cout << "1: display balance\n2: display rate\n3: deposit to account\n4: withdraw from account\n5: accrue interest\n6: exit\n";
}