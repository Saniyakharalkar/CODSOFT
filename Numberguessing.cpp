#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    int number, guess;

    // Generate random number
    srand(time(0));
    number = rand() % 100 + 1;   // random number between 1 to 100

    cout << "=== Number Guessing Game ===\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again.\n";
        }
        else if (guess < number) {
            cout << "Too low! Try again.\n";
        }
        else {
            cout << "Correct! You guessed the number 🎉\n";
        }

    } while (guess != number);

    return 0;
}
