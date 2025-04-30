//-------------------------------+-------------+------------+
// Week 3 - Coding Assignment #0 | Calvin Losh | 24-04-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <cmath>

using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    double distance{sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))};
    return distance;
}

string calculateMidpoint(double x1, double y1, double x2, double y2) {
    double p1{(x1 + y1) / 2};
    double p2{(x2 + y2) / 2};
    string point{"(" + to_string(p1) + ", " + to_string(p2) + ")"};
    return point;
}

int main() {
    double x1, y1, x2, y2;

    cout << "\nWelcome to the distance calculator!"
         << "\nPlease enter in the coordinates of the first point."
         << "\nx1 > ";
    cin  >> x1;
    cout << "y1 > ";
    cin  >> y1;
    cout << "\nNow for the second point."
         << "\nx2 > ";
    cin  >> x2;
    cout << "y2 > ";
    cin  >> y2;
    
    cout << "The distance between ("
         << x1 << ", " << y1 << ") and ("
         << x2 << ", " << y2 << ") is: "
         << calculateDistance(x1, y1, x2, y2)
         << " and the midpoint lies at "
         << calculateMidpoint(x1, y1, x2, y2);
}