#include "commands.h"

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

//-------------------------//

int selection_scrub(int min, int max) {

    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nPlease enter a selection between " << min << " and " << max << "\n> ";
        } else {
            return input;
        }
    }
}

bool selection_scrub() {
    char input;
    while (true) {
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter 'y' or 'n'.\n> ";
            continue;
        }

        input = std::tolower(input);
        if (input == 'y') return true;
        if (input == 'n') return false;

        std::cout << "\nPlease try again and enter either 'y' or 'n'.\n> ";
    }
}

//-------------------------//

void screen_clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
};

//-------------------------//

int roll(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}
