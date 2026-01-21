#include <iostream>
#include <string>
#include <cmath>
int main() {
    int number;
    std::string romanNumeral;

    std::cout << "enter integer bewteen 1 and 10: ";
    std::cin >> number;

    while (std::cin.fail() || number < 1 || number > 10) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "invalid input, please enter integer between 1 and 10: ";
        std::cin >> number;
    }

    while (number > 0) {
        if (number == 10) {
            romanNumeral += "X";
            number -= 10;
        }
        else if (number == 9) {
            romanNumeral += "IX";
            number -= 9;
        }
        else if (number >= 5) {
            romanNumeral += "V";
            number -= 5;
        }
        else if (number == 4) {
            romanNumeral += "IV";
            number -= 4;
        }
        else {
            romanNumeral += "I";
            number -= 1;
        }
    }
    std::cout << romanNumeral << std::endl;
    return 0;
}