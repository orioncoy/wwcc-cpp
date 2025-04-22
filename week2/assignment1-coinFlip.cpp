//-------------------------------+-------------+------------+
// Week 2 - Coding Assignment #1 | Calvin Losh | 21-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int flips{};
    int heads{};
    int tails{};
    double hp{};
    double tp{};

    cout << "\nWelcome to the coin flipper simulator!"
         << "\nHow many coin flips would you like to simulate?"
         << "\n> ";
    cin >> flips;
    cout << "\nSimulating...\n";

    for (int i = 0; i < flips; i++) {
        int j = rand() %2;
        if (j == 0) {tails++;}
        else if (j == 1) {heads++;}
        else {cout << "huh?";}
    }

    hp = (heads * 10)/(flips * 0.1);
    tp = (tails * 10)/(flips * 0.1);

    //percentages are mostly accurate but the printf rounding messes with it a bit.
    cout << "\nHeads: " << heads 
         << " (" << printf("%.1f", hp) << "%)"
         << "\nTales: " << tails
         << " (" << printf("%.1f", tp) << "%)"; 

    return 0;
}