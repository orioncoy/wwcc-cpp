//-------------------------------+-------------+------------+
// Week 2 - Coding Assignment #0 | Calvin Losh | 10-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int     var_int{343};
    float   var_float{3.14159f};
    double  var_double{3.1415926535};
    char    var_char{'z'};
    string  var_string{"string!"};

    cout << "\nFromat Specifier Practice"
         << "\n-=-=-=-=-=-=-=-=-=-=-=-=-"
         << "\n"
         << "\nInteger Formats:"
         << "\nDefault: " << var_int
         << "\nHexadecimal: " << printf("%x", var_int)
         << "\nWidth (10): " << printf("[%10d]", var_int)
         << "\n"
         << "\n-=-=-=-=-=-=-=-=-=-=-=-=-"
         << "\n"
         << "\nFloat Formats:"
         << "\nDefault: " << var_float
         << "\nScientific Notation: " << printf("%e", var_float)
         << "\nPrecision (3): " << printf("%.2f", var_float)
         << "\n"
         << "\n-=-=-=-=-=-=-=-=-=-=-=-=-"
         << "\n"
         << "\nCharacter and String Formats:"
         << "\nDefault String: " << var_string
         << "\nDefault Character: " << var_char;

    return 0;
}