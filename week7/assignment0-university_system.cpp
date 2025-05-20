//-------------------------------+-------------+------------+
// Week 7 - Coding Assignment #0 | Calvin Losh | --2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class c_student {
private:
    std::string name;
    int sid;
    double gpa;

public:
    c_student(std::string name, int sid, double gpa)
        : name(name), sid(sid), gpa(gpa) {}

    std::string get_name() {
        return name;
    }

    int get_sid() {
        return sid;
    }

    double get_gpa() {
        return gpa;
    }

    void update_gpa(double updated_gpa) {
        gpa = updated_gpa;
    }
};

class c_course {
private:
    std::string code;
    std::string title;
    int cred_hrs;

public:
    c_course(std::string code, std::string title, int cred_hrs)
        : code(code), title(title), cred_hrs(cred_hrs) {}

    std::string get_code() {
        return code;
    }

    std::string get_title() {
        return title;
    }

    int get_cred_hrs() {
        return cred_hrs;
    }
};

void student_init (vector<c_student> &student) {
    student.push_back([] {
        c_student alex_j(
            "Alex Johnson",
            1001,
            3.75
        );
        return alex_j;
    }());

    student.push_back([] {
        c_student maria_g(
            "Maria Garcia",
            1002,
            3.92
        );
        return maria_g;
    }());

    student.push_back([] {
        c_student jamal_w(
            "Jamal Williams",
            1003,
            3.45
        );
        return jamal_w;
    }());
}

void course_init (vector<c_course> &course) {
    course.push_back([] {
        c_course cs101(
            "CS101",
            "Introduction to Programming",
            3
        );
        return cs101;
    }());

    course.push_back([] {
        c_course math202(
            "MATH202",
            "Calculus II",
            4
        );
        return math202;
    }());
}

void gpa_scrub(string &inp, int min, int max) {
    bool lbreak = true;
    while (lbreak) {
        try {
            double iinp = stod(inp);
            if (!(iinp < min) || !(iinp > max)) {
                inp = to_string(iinp);
                lbreak = false;
            } else {
                cout << "Please enter a number between " << min << " and " << max << "\n> ";
                getline(cin, inp);
            }
        } catch(invalid_argument) {
            cout << "Please enter a number\n> ";
            getline(cin, inp);
        } catch(const exception& e) {
            cout << "Please try again\n> ";
            getline(cin, inp);
        }
    }
}

void student_scrub(string &target, int &sid, vector<c_student> &student) {
    bool nfound = true;
    while (nfound) {
        for (int i = 0; i < student.size(); i++) {
            if (student.at(i).get_name() == target) {
                sid = student.at(i).get_sid();
                nfound = false;
                break;
            }
        }
        if (nfound) {
            cout << "This student: " << target << ", does not exist, please try again.\n> ";
            getline(cin, target);
        }
    }
}

void printer(vector<c_student> &student, vector<c_course> &course) {
        cout << "\nUNIVERSITY MANAGEMENT SYSTEM"
         << "\n----------------------------"
         << "\n"
         << "\nStudent information";

    for (int i = 0; i < student.size(); i++) {
        string name = student.at(i).get_name();
        double gpa = student.at(i).get_gpa();
        int sid = student.at(i).get_sid();

        cout << "\nID: " << sid << " - " << name
             << "\nGPA: " << gpa << endl;
    }

    cout << "\nCourse Information";

    for (int i = 0; i < course.size(); i++) {
        string code = course.at(i).get_code();
        string title = course.at(i).get_title();
        int cred_hrs = course.at(i).get_cred_hrs();

        cout << code << ": " << title << " (" << cred_hrs << " credits)\n";
    }
}

int main() {
    vector<c_student> student;
    vector<c_course> course;
    string gpa_inp;
    string std_inp;
    int sid_im_lazy;

    student_init(student);
    course_init(course);
    printer(student, course);

    
    cout << "\nStudent GPA updater"
         << "\nEnter the whole name of the student\n> ";

    getline(cin, std_inp);
    student_scrub(std_inp, sid_im_lazy, student);
    cout << "\nEnter the updated GPA\n> ";
    getline(cin, gpa_inp);
    gpa_scrub(gpa_inp, 0, 4);

    cout << "\nID:" << sid_im_lazy << " - " << std_inp
             << "\nGPA: " << gpa_inp << endl;
}