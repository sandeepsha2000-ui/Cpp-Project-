// number guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    
    int number = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Can you guess it?" << endl;

    // Loop until the user guesses correctly
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "🎉 Congratulations! You guessed the number " 
                 << number << " in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
