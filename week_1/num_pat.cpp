//-------------------------------+-------------+------------+
// Week 1 - Coding Assignment #5 | Calvin Losh | 10-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string k;
    cout << "enter a number between 1 and 9 \n> ";
    cin >> n;

    if (n > 9 or n < 1) {
        cout << "please enter a number in the given range please.";
    }
    else {
        for (int i = 1; i <= n; i++) {
            string j = to_string(i);
            k = k + j + " ";
            cout << k << " \n";
        }
    }

    return 0;
}