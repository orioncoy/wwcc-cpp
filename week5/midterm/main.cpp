//------------------+-------------+------------+
// Week 5 - Midterm | Calvin Losh | 12-05-2025 |
//------------------+-------------+------------+
// main.cpp - main entry point, handles interface and navigation
//
// Project - Task Manager
//
// To-Do List
// [X] Add tasks with title, description, priority and due date
// [X] Mark tasks as complete/incomplete
// [X] Display tasks sorted by priority or due date
// [ ] Filter tasks by status
// [X] Generate productivity reports
//

#include <cstdlib>

#include "main.h"

using namespace std;

void interface(vector<s_task> &tasks, int &step, string &target) {
    switch (step) {
    case 0: // init
        init(tasks, step, target);
        break;
    case 1: // add task
        add_task(tasks, step, target);
        break;
    case 2:
        abort();// quits the app
    case 3: // update task
        complete_task(tasks, step, target);
        break;
    case 4: // view tasks
        print_task(tasks, step, target);
        break;
    case 5: // sort tasks
        sort_task(tasks, step, target);
        break;
    case 6: // help
        help(step);
        break;
    default:
        step = 0;
        break;
    }
};

// clears the terminal based on the OS, should work for most cases
void terminal_clear() {
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
};

void help(int &step) {
    terminal_clear();
    cout << "\n               [ HELP ]"
         << "\n+-------+----------+--------------------+"
         << "\n|  cmd  |   desc   |       format       |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -a   | add      | -a  [name of task] |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -c   | complete | -c  [name of task] |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -v   | view     | -v  [name of task] |"
         << "\n|       |          | -v  -all           |"
         << "\n|       |          | -v  -recent        |"
         << "\n|       |          | -v  -complete      |"
         << "\n|       |          | -v  -incomplete    |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -s   | sort     | -s  -status        |"
         << "\n|       |          | -s  -duedate       |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -q   | quit     | -q                 |"
         << "\n+-------+----------+--------------------+";

    step = 0;
}

// returns the index where a target index is at
bool locate_element(vector<s_task> &vec, string target, int &target_index) {
    bool found = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i).name == target) {
            target_index = i;
            found = true;
            break;
        }
    }
    if (!found) {
        terminal_clear();
        cout << target << " is not a valid argument! Please try again.";
    }
    return found;
}

// overload for
bool locate_element(vector<s_task> &vec, int target_index) {
    bool found = false;
    if (!vec.empty()) {
        found = true;
    } else {
        cout << "\nThere are no tasks available, please add one and try again.";
    }
    return found;
}

void init(vector<s_task> &tasks, int &step, string &target) {
    string inp{};
    prod_rpt(tasks, step);
    cout << "\nPlease enter a command or type '-h' for help\n> ";
    getline(cin, inp);
    inp_parser(tasks, step, inp, target);
}

int main() {
    terminal_clear();
    vector<s_task> tasks;
    int step = 0;
    string target = "";
    cout << "Welcome to the task manager!";
    while (true) {
        interface(tasks, step, target);
    }
}