//-------------------------------+-------------+------------+
// Week 2 - Coding Assignment #2 | Calvin Losh | 21-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int randNum{rand() % 100 + 1};
    int guess{};
    int attempts{1};
    bool loop{true};

    cout << "\nNumber Guessing Game!"
         << "\nI am thinking of a number between 1 and 100... what could it be???\n> ";

    do {
        cin >> guess;
        if (guess != randNum) {
            if (guess > randNum) {cout << "\nToo high, ";}
            if (guess < randNum) {cout << "\nToo low, ";}
            cout << "Try again! (attempt: " << attempts << ")\n> ";
            attempts++;
            continue;
        } 
        else if (guess == randNum) {
            cout << "\nCongrats! you guessed it!" << endl;
            loop = false;
        } 
        else {cout << "huh?!?";}
    } while(loop);
    return 0;
}