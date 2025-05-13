//------------------+-------------+------------+
// Week 5 - Midterm | Calvin Losh | 12-05-2025 |
//------------------+-------------+------------+
// main.cpp - main entry point, handles interface and navigation
// Project - Task Manager
// to do List
// [X] Add tasks with title, description, priority and due date
// [ ] Mark tasks as complete/incomplete
// [ ] Display tasks sorted by priority or due date
// [ ] Filter tasks by status (pending/complete)
// [ ] Generate productivity reports (tasks completed per week)

#include <cstdlib>

#include "main.h"

using namespace std;

void interface(vector<s_task> &tasks, int &step, string target) {
    switch (step) {
    case 0: // init
        init(tasks, step);
        break;

    case 1: // add task
        add_task(tasks, step, target);
        break;

    case 2:
        abort();// remove task
        remove_task(tasks, step, target);
        break;

    case 3: // update task
        update_task(tasks, step, target);
        break;

    case 4: // view tasks
        print_task(tasks, step, target);
        break;

    case 5: // sort tasks
        sort_task(tasks, step);
        break;

    case 6: // print report
        prod_rpt(tasks, step);
        break;

    case 7: // help
        help(tasks, step);
        break;

    default:
        break;
    }
};

void interface(std::vector<s_task> &tasks, int &step) {
    interface(tasks, step, "");
}

// clears the terminal based on the OS, should work for most cases
void terminal_clear() {
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

//
void inp_clean() {
    cin.clear();
    cin.ignore(INT_MAX);
}


void help(vector<s_task> &vec, int &step) {
    cout << "\n               [ HELP ]"
         << "\n+-------+--------+--------------------+"
         << "\n|  cmd  |  desc  | format             |"
         << "\n+-------+--------+--------------------+"
         << "\n|  -a   | add    | -a  [name of task] |"
         << "\n|  -r   | remove | -r  [name of task] |"
         << "\n|  -u   | update | -u  [name of task] |"
         << "\n|  -v   | view   | -v  [name of task] |"
         << "\n|  -s   | sort   | -s  [name of task] |"
         << "\n|  -pr  | report | -pr                |"
         << "\n+-------+--------+--------------------+";

    // routes the user back to the main menu
    step = 0;
}

// returns the index where a target index is at
int locate_element(vector<s_task> &vec, string target) {
    int target_index{};
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i).name == target) {
            target_index = i;
            break;
        }
    }
    return target_index;
}

void init(vector<s_task> &tasks, int &step) {
    //terminal_clear();
    string inp{};
    cout << "\nPlease enter a command or type '-h' for help\n> ";
    getline(cin, inp);
    inp_parser(tasks, step, inp);
}

int main() {
    vector<s_task> tasks;
    int step{0};

    cout << "\nWelcome to the task manager!";
    while (true) {
        interface(tasks, step);
    }
}