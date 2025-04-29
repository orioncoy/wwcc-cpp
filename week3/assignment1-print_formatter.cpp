//-------------------------------+-------------+------------+
// Week 3 - Coding Assignment #1 | Calvin Losh | 28-04-2025 |
//-------------------------------+-------------+------------+
// Overloaded functions and formatting                      |
//----------------------------------------------------------+

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// formats an int with commas
string format(int inp) {
    string s_inp{to_string(inp)};

    for(int i = s_inp.length() - 3; i > 0; i -= 3) {
        s_inp.insert(i, ",");
    }
    
    return s_inp;
}

//formats a double into a string and rounds the double to 2 decimal places
string format(double inp) {
    string r_inp{to_string(printf("%0.1f",inp))};
    return r_inp;
}

//formats a double to have a specified amount of decimal places
double format(double inp, int d_place) {
    double r_inp{};
    // turning the input into a decimal place that printf can use and formatting for printf
    string dp{"%." + to_string(d_place - 1) + "f"}; 
    // turning the dp string into a char array that printf can accept
    const char* cc_p{dp.c_str()};

    r_inp = printf(cc_p, inp);
    return r_inp;
}

//formats a string to capitalize the first letter in every word
string format(string inp) {
    string r_inp{};
    const char* c_inp{r_inp.c_str()};
    
    //this one stumped me
    return r_inp;
}

int main() {
    int v_int{123456789};
    int v_dec_p{6};
    double v_doub{45.6789};
    string v_str{"hello there!"};

    cout << "\nInteger Formatting:\n" << v_int << " with commas: " << format(v_int) << "\n";
    cout << "\nDouble Formatting: (fixed and custom decimal places, respectively)\n" << v_doub << " to 2 decimal point(s): " << format(v_doub) << "\n";
    cout << v_doub << " to " << v_dec_p << " decimal point(s): " << format(v_doub, v_dec_p) << "\n";
}