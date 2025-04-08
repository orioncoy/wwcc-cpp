#include <iostream>

using namespace std;

int main() {
    double n1, n2;

    cout << "Welcome to the basic calculator!\nPlease enter your first number.\n> ";
    cin >> n1;
    cout << "Please enter your second number\n> ";
    cin >> n2;

    cout << "\nResults:\n";
    cout << "Sum: " << n1 << " + " << n2 << " = " << n1 + n2;
    cout << "\nDifference: " << n1 << " - " << n2 << " = " << n1 - n2;
    cout << "\nProduct: " << n1 << " * " << n2 << " = " << n1 * n2;
    if (n2 == 0) {
        cout << "\nQuotient: You cannot divide by zero!";
    }
    else {
        cout << "\nQuotient: " << n1 << " / " << n2 << " = " << n1 / n2;
    }
}