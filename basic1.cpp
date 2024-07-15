#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    int lowerBound = 1;   // Lower bound of the number range
    int upperBound = 100; // Upper bound of the number range
    int numberToGuess = rand() % (upperBound - lowerBound + 1) + lowerBound;  // Generate the random number

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between " << lowerBound << " and " << upperBound << ". Guess what it is!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << numberToGuess << " correctly in " << attempts << " attempts!" << endl;
        }
    } while (guess != numberToGuess);

    return 0;
}
