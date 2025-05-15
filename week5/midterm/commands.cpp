//------------------+-------------+------------+
// Week 5 - Midterm | Calvin Losh | 12-05-2025 |
//------------------+-------------+------------+
// commands.cpp - handling the commands of the program

#include "main.h"

using namespace std;

void add_task(vector<s_task> &vec, int &step, string name) {
    s_task tsk_temp{};
    string inp_temp{};
    tsk_temp.name = name;

    cout << "\nEnter a description for " << name << ": ";
    getline(cin, tsk_temp.desc);

    cout << "Enter the priority (1 to 5, least to most): ";
    getline(cin, inp_temp);
    inp_scrub(inp_temp, tsk_temp.priority, 1, 5);

    cout << "Enter the due day: ";
    getline(cin, inp_temp);
    inp_scrub(inp_temp, tsk_temp.due_date.day, 1, 31);

    cout << "Enter the due month: ";
    getline(cin, inp_temp);
    inp_scrub(inp_temp, tsk_temp.due_date.month, 1, 12);

    cout << "Enter the due year: ";
    getline(cin, inp_temp);
    inp_scrub(inp_temp, tsk_temp.due_date.year);

    terminal_clear();

    cout << "Task successfully created!"
            "\nBy default, all tasks are marked as 'incomplete' on creation. "
            "\nYou can complete tasks with the '-c [task name]' command.\n";

    vec.push_back(tsk_temp);
    step = 0;
};

void complete_task(vector<s_task> &vec, int &step, string target) {
    terminal_clear();
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i).name == target) {
            vec.at(i).complete = true;
            cout << "Task: " << vec.at(i).name << " is marked as complete!";
            break;
        }
    }
    step = 0;
}

void print_task(vector<s_task> &vec, int &step, string target) {
    int target_index{};
    string name{};
    string desc{};
    string stat{};
    string date{};
    bool found{false};

    if (target == "-recent") {
        target_index = vec.size() - 1;
        found = locate_element(vec, target_index);
    } else if (target == "-all" && vec.size() > 0) {
        terminal_clear();
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i).complete) {
                stat = "Complete";
            } else {
                stat = "Incomplete";
            }
            cout << "\nTask: " << vec.at(i).name
                 << "\n - Description: " << vec.at(i).desc
                 << "\n - Priority: " << vec.at(i).priority
                 << "\n - Due Date: "
                    << to_string(vec.at(i).due_date.day) << "-"
                    << to_string(vec.at(i).due_date.month) << "-"
                    << to_string(vec.at(i).due_date.year)
                 << "\n - Status: " << stat;
        }
    } else if (target == "-complete") {
        terminal_clear();
        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i).complete) {
                stat = "Complete";
                cout << "\nTask: " << vec.at(i).name
                     << "\n - Description: " << vec.at(i).desc
                     << "\n - Priority: " << vec.at(i).priority
                     << "\n - Due Date: "
                        << to_string(vec.at(i).due_date.day) << "-"
                        << to_string(vec.at(i).due_date.month) << "-"
                        << to_string(vec.at(i).due_date.year)
                     << "\n - Status: " << stat;
            }
        }
    } else if (target == "-incomplete") {
        terminal_clear();
        for (int i = 0; i < vec.size(); i++) {
            if (!vec.at(i).complete) {
                stat = "Incomplete";
                cout << "\nTask: " << vec.at(i).name
                     << "\n - Description: " << vec.at(i).desc
                     << "\n - Priority: " << vec.at(i).priority
                     << "\n - Due Date: "
                        << to_string(vec.at(i).due_date.day) << "-"
                        << to_string(vec.at(i).due_date.month) << "-"
                        << to_string(vec.at(i).due_date.year)
                     << "\n - Status: " << stat;
            }
        }
    } else {
        found = locate_element(vec, target, target_index);
    }

    if (found) {
        terminal_clear();
        if (vec.at(target_index).complete) {
            stat = "Complete";
        } else {
            stat = "Incomplete";
        }
        cout << "\nTask: " << vec.at(target_index).name
             << "\n  Description: " << vec.at(target_index).desc
             << "\n - Priority: " << vec.at(target_index).priority
             << "\n  Due Date (DD-MM-YYYY): "
                << to_string(vec.at(target_index).due_date.day) << "-"
                << to_string(vec.at(target_index).due_date.month) << "-"
                << to_string(vec.at(target_index).due_date.year)
             << "\n  Status: " << stat;
    }

    step = 0;
};

void sort_task(vector<s_task> &vec, int &step, string target) {
    if (target == "-status") {
        vector<s_task> incmp;
        vector<s_task> cmp;

        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i).complete) {
                cmp.push_back(vec.at(i));
            } else if (!vec.at(i).complete) {
                incmp.push_back(vec.at(i));
            } else {
                // feel the need for something here
            }
        }

        // overwrites original vector with sorted vector, starting with complete
        for (int i = 0; i < cmp.size(); i++) {
            vec.at(i) = cmp.at(i);
        }

        // moves on to incomplete vectors, starting at the index where complete left off
        for (int i = cmp.size() - 1; i < incmp.size(); i++) {
            vec.at(i + cmp.size()) = incmp.at(i);
        }

    } else if (target == "-priority") {
        sort(vec.begin(), vec.end(), [](const s_task& a, const s_task& b) {
            return a.priority < b.priority;
        });
        
    } else {

    }
    step = 0;
};

void prod_rpt(vector<s_task> &vec, int &step) {
    int completed_tasks{};
    int active_tasks{};

    cout << "\n\nProductivity Report"
         << "\n~~~~~~~~~~~~~~~~~~~"
         << "\nTotal tasks: " << vec.size();

    if (!vec.empty()) {
        for (int i = 0; i < vec.size(); i++) {
            if (!vec.at(i).complete) {
                active_tasks++;
            } else if (vec.at(i).complete) {
                completed_tasks++;
            }
        }

        cout << "\nActive Tasks: " << active_tasks
             << "\nComplete Tasks: " << completed_tasks;
    }

    cout << "\n~~~~~~~~~~~~~~~~~~~\n";
    step = 0;
};