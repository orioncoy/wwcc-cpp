//-------------------------------+-------------+------------+
// Week 1 - Coding Assignment #3 | Calvin Losh | 08-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>

using namespace std;

int main() {
    double temp;
    char unit;

    cout << "Hello, please enter a temperature value.\n> ";
    cin >> temp;
    cout << "Now please specify the unit of this temperature. (C for celcius, F for fahrenheit)\n> ";
    cin >> unit;

    if (unit == 'F') {
        cout << temp << "F in C is: " << (temp - 32) * 5 / 9 << "C.";
    }
    else if (unit == 'C') {
        cout << temp << "C in F is: " << (temp * 9/5) + 32 << "F.";
    }
    else {
        cout << "It looks like your unit selection was invalid, please try again and be sure to remember this program is case sensitive.";
    }
    return 0;
}