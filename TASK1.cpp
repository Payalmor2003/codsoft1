#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;

    std::cout << "Welcome to the NUMBER GUESSING GAME!\n";
    std::cout << "I have chosen a number between 1 and 100. Try to guessing it.\n";

    int userGuess;
    int userAttempts = 0;

    while (true)
    {
        // Get user's guess
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        userAttempts++;

        // Check if the guess is correct
        if (userGuess == secretNumber)
        {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << userAttempts << " attempts.\n";
            break;
        }
        else if (userGuess < secretNumber)
        {
            std::cout << "Too low! Give another try again.\n";
        }
        else
        {
            std::cout << "Too high! Give another try again.\n";
        }
    }

    return 0;
}
