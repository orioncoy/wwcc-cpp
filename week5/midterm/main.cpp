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
// [X] Display tasks sorted by priority or completion
// [X] Filter tasks by status
// [X] Generate productivity reports
//

#include "main.h"

// only needed for windows compilation
#ifdef _WIN32 || _WIN64
#include <cstdlib>
#endif

using namespace std;

// The 'train station' that routes the user depending on what step is
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
        view_task(tasks, step, target);
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

// clears the terminal based on OS
void terminal_clear() {
    #ifdef _WIN32 || _WIN64
        system("cls");
    #elif __APPLE__ || __linux__
        system("clear");
    #endif
};

// simple help interface
void help(int &step) {
    terminal_clear();
    cout << "               [ HELP ]"
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
         << "\n|       |          | -s  -priority      |"
         << "\n+-------+----------+--------------------+"
         << "\n|  -q   | quit     | -q                 |"
         << "\n+-------+----------+--------------------+\n\n";

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
        cout << "\033[1;31m" << target << " is not a valid argument! Please try again.\033[0m\n\n";
    }
    return found;
}

// overload for
bool locate_element(vector<s_task> &vec, int target_index) {
    bool found = false;
    if (!vec.empty()) {
        found = true;
    } else {
        cout << "\033[1;31mThere are no tasks available, please add one and try again.\033[0m\n\n";
    }
    return found;
}

// Main menu that takes users input and passes it into inp parser
void init(vector<s_task> &tasks, int &step, string &target) {
    string inp{};
    prod_rpt(tasks, step);
    cout << "\nPopular Commands!\n"
         << "\n-a [task name here] | Adds a new task"
         << "\n-c [task name here] | Mark a task as complete"
         << "\n-v -[argument here] | View your tasks"
         << "\n-s -[argument here] | Sort your tasks\n"
         << "\nPlease enter a command or type '-h' for help\n> ";
    getline(cin, inp);
    inp_parser(tasks, step, inp, target);
}

int main() {
    terminal_clear();
    vector<s_task> tasks;
    int step = 0;
    string target = "";
    cout << "\033[1;32mWelcome to the task manager!\033[0m\n\n";
    while (true) {
        interface(tasks, step, target);
    }
}