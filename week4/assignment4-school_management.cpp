//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #4 | Calvin Losh | 07-05-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

struct Address {
    string street;
    string city;
    string state;
    int zip;
};
struct Person {
    string name;
    int age;
    Address address;
};
struct Course {
    int course_code;
    string name;
    double credit_hours;
};
struct Student {
    Person person;
    int sid;
    double gpa;
    string courses[5] {
        "",
        "",
        "",
        "",
        ""
    };
};

int main() {
    
}