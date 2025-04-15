//-------------------------------+-------------+------------+
// Week 1 - Coding Assignment #1 | Calvin Losh | 07-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string flavor;

    cout << "Please enter your name.\n> ";
    getline(cin, name);
    cout << "Nice to meet you, " << name;
    cout << "\nWhat is your favorite ice cream flavor? \n> ";
    getline(cin, flavor);
    cout << "I have to agree, " << name << ", " << flavor << " flavor does taste great!";
    return 0;
}