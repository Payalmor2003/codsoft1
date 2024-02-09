#include <iostream>

int main()
{
    char operation;
    double number1, number2, result;

    std::cout << "Enter first number: ";
    std::cin >> number1;

    std::cout << "Enter second number: ";
    std::cin >> number2;

    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation)
    {
    case '+':
        result = number1 + number2;
        break;
    case '-':
        result = number1 - number2;
        break;
    case '*':
        result = number1 * number2;
        break;
    case '/':
        if (number2 != 0)
        {
            result = number1 / number2;
        }
        else
        {
            std::cout << "Error: Division by zero is not allowed.\n";
            return 1;
        }
        break;
    default:
        std::cout << "Error: Invalid operation. Please enter a valid operation. \n";
        return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
