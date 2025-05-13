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

    cout << "\nEnter a description for " << tsk_temp.name << ": ";
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

    cout << "By default, all tasks are marked as 'incomplete' "
            "on creation, you can update this in the update menu.\n";

    vec.push_back(tsk_temp);
    step = 0;
};

void remove_task(vector<s_task> &vec, int &step, string target) {

}

void update_task(vector<s_task> &vec, int &step, string target) {

}

void print_task(vector<s_task> &vec, int &step, string target) {

};

void sort_task(vector<s_task> &vec, int &step) {

};

void prod_rpt(vector<s_task> &vec, int &step) {

};