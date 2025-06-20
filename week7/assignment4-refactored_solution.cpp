//-------------------------------+-------------+------------+
// Week 7 - Coding Assignment #4 | Calvin Losh | --2025 |
//-------------------------------+-------------+------------+

#include <iostream>

using namespace std;

// - ACCOUNT CLASS - // ----------------------- //

class account {
private:
    string customerName;
    double money;
    bool open;
    int acc_number;
    string type;
public:
    account(string customerName, double money, bool open, int acc_number, string type)
    :   customerName(customerName), money(money), open(open), acc_number(acc_number), type(type) {}

    // - INLINE - //

    string get_customer() {
        return customerName;
    }

    double get_balance() {
        return money;
    }

    int get_acc_num() {
        return acc_number;
    }

    string get_type() {
        return type;
    }

    void deposit(double x) {
        this->money = money + x;
    }

    void withdraw(double x) {
        this->money = money - x;
    }

    void close() {
        open = false;
    }
    
    // - PROTOS - //

    void setup(string n, int num, string t);
    void do_interest();
    void print();
};

void do_interest() {
    if (account::get_type == "savings") {
        money = money * 1.03;
    } else if (type == "checking") {
        money = money * 1.01;
    } else if (type == "business") {
        money = money * 1.005;
    }
}

void print() {
    cout << "Account Number: " << acc_number << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Balance: $" << money << endl;
    cout << "Account Type: " << type << endl;
    cout << "Status: " << (open ? "Open" : "Closed") << endl;
}


// - MAIN - // ----------------------- //

int main() {
    // Create an account
    account acc1;
    acc1.setup("John Smith", 12345, "savings");

    // Perform operations
    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.do_interest();

    // Display information
    acc1.print();

    // Close the account
    acc1.close();

    return 0;
}