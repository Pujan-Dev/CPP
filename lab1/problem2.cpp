// Write a program that determines the maximum and the minimum of three numbers.
#include <iostream>

int main() {
    int num1, num2, num3;    
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter third number: ";
    std::cin >> num3;

    int maxNum, minNum;

    if (num1 >= num2 && num1 >= num3) {
        maxNum = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        maxNum = num2;
    } else {
        maxNum = num3;
    }

    if (num1 <= num2 && num1 <= num3) {
        minNum = num1;
    } else if (num2 <= num1 && num2 <= num3) {
        minNum = num2;
    } else {
        minNum = num3;
    }

    std::cout << "Maximum number: " << maxNum << std::endl;
    std::cout << "Minimum number: " << minNum << std::endl;

    return 0;
}
