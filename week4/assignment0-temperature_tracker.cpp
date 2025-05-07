//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #0 | Calvin Losh | 02-05-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

int main() {
    int temp[7] = {};
    int temp_high[2] = {};
    int temp_low[2] = {};
    int temp_tot = {0};
    double temp_avg = {0};

    cout << "\nTemperature Tracker"
         << "\n-------------------\n";

    for (int i = 0; i < 7; i++) {
        cout << "Enter the temp for day " << i + 1 << ": ";
        cin >> temp[i];
    }

    cout << "\nTemperature Analysis"
         << "\n--------------------";

    temp_low[1] = temp[0];
    for (int i = 0; i < 7; i++) {
        if (temp[i] < temp_low[1]) {
            temp_low[0] = i;
            temp_low[1] = temp[i];
        }
    }

    for (int i = 0; i < 7; i++) {
        if (temp[i] > temp_high[1]) {
            temp_high[0] = i;
            temp_high[1] = temp[i];
        }
    }

    for (int i = 0; i < 7; i++) {
        temp_tot += temp[i];
    }

    temp_avg = temp_tot / 7;

    cout << "\nHighest temperature: " << temp_high[1] << " (day " << temp_high[0] + 1<< ")"
         << "\nLowest temperature: " << temp_low[1] << " (day " << temp_low[0] + 1<< ")"
         << "\nAverage temperature: " << temp_avg << "\n";

    cout << "\nDays with above average temperatures"
         << "\n------------------------------------";

    for (int i = 0; i < 7; i++) {
        if (temp[i] > (temp_tot/7)) {
            cout << "\nDay " << i + 1 << ": " << temp[i];
        }
    }
    return 0;
}
