//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #4 | Calvin Losh | 07-05-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>

using namespace std;

struct Address {
    string street{};
    string city{};
    string state{};
    int zip{};
};
struct Person {
    string name{};
    int age{};
    Address address{};
};
struct Course {
    string code{};
    string name{};
    int cred_hr{};
};
struct Student {
    Person person{};
    int sid{};
    double gpa{};
    Course courses[5]{};
};

void student_init(Student &mar, Student &jam, Student &sar) {

    mar = {
        { // Person
            "Marisa Rodriquez",
            20, 
            { // Address
                "123 College Ave",
                "Berkeley",
                "CA",
                94704
            },
        },
        1001,
        3.85,
        { // Courses
            {"CS101", "Introduction to Programming", 3},
            {"MATH201", "Calculus II", 4},
            {"PHYS101", "Physics I", 4},
            {"ENG105", "English Composition", 3},
            {"HIST100", "World History", 3}
        }
    };

    jam = {
        { // Person
            "James Smith",
            19, 
            { // Address
                "456 University Dr",
                "Berkeley",
                "CA",
                94704
            },
        },
        1002,
        3.42,
        { // Courses
            {"CS101", "Introduction to Programming", 3},
            {"MATH101", "Calculus I", 4},
            {"CHEM101", "Chemistry I", 4},
            {"SOC200", "Introduction to Sociology", 3},
            {"ART105", "Drawing Fundamentals", 2}
        }
    };

    sar = {
        { // Person
            "Sarah Johnson",
            21, 
            { // Address
                "789 Campus Rd",
                "Berkeley",
                "CA",
                94704
            },
        },
        1003,
        3.91,
        { // Courses
            {"CS201", "Data Structures", 3},
            {"MATH201", "Calculus II", 4},
            {"BIO101", "Biology I", 4},
            {"PSYCH101", "Introduction to Psychology", 3},
            {"ECON200", "Microeconomics", 3}
        }
    };
}

void print(Student student) {
    cout << "\nID: " << student.sid << " - " << student.person.name
         << "\nAGE: " << student.person.age
         << "\nADDRESS: " << student.person.address.street << ", " << student.person.address.city << ", " << student.person.address.state << " " << student.person.address.zip
         << "\nGPA: " << student.gpa
         << "\nCOURSES:";
    for (int i{0}; i < 5; i++) {
        cout << "\n    " << student.courses[i].code << ": " << student.courses[i].name << " (" << student.courses[i].cred_hr << " credits)";
    }
    cout << endl;
}

void gpa_avg(double &gpa_avg, double mar_gpa, double jam_gpa, double sar_gpa) {
    gpa_avg = (mar_gpa + jam_gpa + sar_gpa) / 3 ;
}

void find_by_id(Student arr[]) {
    int inp_sid{};
    bool found{false};

    cout << "\nEnter the student ID to search: ";
    cin >> inp_sid;

    for (int i = 0; i < 3; i++) {
        if (arr[i].sid == inp_sid) {
            cout << "\nStudent Found"
                 << "\n    Name: " << arr[i].person.name << " (ID: " << inp_sid << ")"
                 << "\n    GPA: " << arr[i].gpa;
            found = true;
        }
    }

    if (!found) {
        cout << "\nSorry, your input was either invlaid or no students have that ID, please try again.";
    }

}

void find_by_class(Student arr[]) {
    string inp_cc{};
    bool found{false};

    cout << "\nEnter the course code to search: ";
    cin >> inp_cc;
    cout << "\nStudents taking " << inp_cc;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i].courses[j].code == inp_cc) {
                cout << "\n    " << arr[i].person.name << " (ID: " << arr[i].sid << ")";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "\nSorry, your input was either invlaid or no students are enrolled in that class, please try again.";
    }
}

int main() {
    Student marisa_r;
    Student james_s;
    Student sarah_j;
    
    double gpa_average{};

    student_init(marisa_r, james_s, sarah_j);
    Student student_arr[3]{marisa_r, james_s, sarah_j};

    cout << "\nSCHOOL MANAGEMENT SYSTEM:"
         << "\n-------------------------"
         << "\nStudent information:\n";

    print(marisa_r);
    print(james_s);
    print(sarah_j);

    gpa_avg(gpa_average, marisa_r.gpa, james_s.gpa, sarah_j.gpa);

    cout << "\nAverage GPA: " << gpa_average;

    find_by_id(student_arr);
    find_by_class(student_arr);

    return 0;
}