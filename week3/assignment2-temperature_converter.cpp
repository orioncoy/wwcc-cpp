//-------------------------------+-------------+------------+
// Week 3 - Coding Assignment #2 | Calvin Losh | 28-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>

using namespace std;

void convertTemperature(char unit, double user_temp, double &C, double &F, double &K) {
    if (unit == 'C') {
        C = user_temp;
        F = ((user_temp * 9/5) + 32); 
        K = (user_temp + 273.15);
    } else if (unit == 'F') {
        F = user_temp;
        K = ((user_temp - 32) * 5 / 9 + 273.15);
        C = ((user_temp - 32) * 5 / 9);
    } else if (unit == 'K') {
        K = user_temp;
        F = ((user_temp - 273.15) * 9 / 5 + 32);
        C = (user_temp - 273.15);
    }
}

int main() {
    double C{};
    double F{};
    double K{};
    double u_temp{};
    char u_unit{};

    // For debugging and testing purposes, just swap out the params
    double t_temp{37.12};
    char t_unit{'C'};

    cout << "\nPlease enter a temperature value\n> ";
    cin >> u_temp;
    while (true) {
        cout << "\nNow please enter the unit,\n(C for Celcius, F for Farhenheit, K for Kelvin)\n> ";
        cin >> u_unit;
        cout << u_unit;
        if (u_unit == 'C' || u_unit == 'K' || u_unit == 'F') {
            break;
        } else {
            cout << "That is an invalid unit or formatting, please mind case sensitivity and try again.\n";
            continue;
        }
    }

    convertTemperature(u_unit, u_temp, C, F, K);

    cout << "\nTemperature Conversions:"
         << "\nCelcius: " << printf("%.1f", C) << " C"
         << "\nFarhenheit: " << printf("%.1f", F) << " F"
         << "\nKelvin: " << printf("%.1f", K) << " K";

    return 0;
}