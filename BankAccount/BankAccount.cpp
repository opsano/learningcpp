#include <iostream>
#include "account.h"
void printMenu(); // function prototype;

int main() {
	bool result;
	int choice = 0;
	Account myAccount(500.00, 2.0);
	do {
		printMenu();
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "invalid input, please enter a number between 1 and 6\n";
			continue;
		}
		switch (choice) {
			case 1: 
				myAccount.displayBalance();
				break;
			case 2:
				myAccount.displayRate();
				break;
			case 3:
				double depositAmount;

				std::cout << "enter depost amount: ";
				std::cin >> depositAmount;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "invalid input, aborting\n";
					continue;
				}
				result = myAccount.deposit(depositAmount);
				if (result) {
					std::cout << "deposit successful\n";
					break;
				}
				std::cout << "deposit unsuccessful\n";
				break;
			case 4:
				double withdrawAmount;

				std::cout << "enter withdraw amount: ";
				std::cin >> withdrawAmount;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "invalid input, aborting\n";
					continue;
				}
				result = myAccount.withdraw(withdrawAmount);
				if (result) {
					std::cout << "withdraw successful\n";
					break;
				}
				std::cout << "withdraw unsuccessful\n";
				break;
			case 5:
				int months;

				std::cout << "enter number of months to accrue: ";
				std::cin >> months;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "invalid input, aborting\n";
					continue;
				}

				result = myAccount.accrueInterest(months);
				if (result) {
					std::cout << "accural successful\n";
					break;
				}
				std::cout << "accrual unsuccessful\n";
				break;
			case 6:
				std::cout << "byebye!";
				return 0;
			default:
				std::cout << "please choose an option in the bounds of our menu\n"; 
		}
	} while (choice != 6);
	
	return 0;
}

void printMenu() {
	std::cout << "enter the operation you would like to preform\n";
	std::cout << "1: display balance\n2: display rate\n3: deposit to account\n4: withdraw from account\n5: accrue interest\n6: exit\n";
}