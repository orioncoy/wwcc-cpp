//------------------+-------------+------------+
// Week 5 - Midterm | Calvin Losh | 12-05-2025 |
//------------------+-------------+------------+
// commands.cpp - handling the commands of the program

#include "main.h"

// Same issue here with the ifdef
// Also, on linux I needed this import as well

// only needed for windows compilation
// #ifdef _WIN32 || _WIN64
#if defined(_WIN32) || defined(_WIN64)
#include <algorithm>
#endif
#include <algorithm>

using namespace std;

// main prompt for adding a task
void add_task(vector<s_task> &vec, int &step, string name)
{
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

    cout << "\033[1;32mTask: " << name << " successfully created!"
                                          "\nBy default, all tasks are marked as 'incomplete' on creation. "
                                          "\nYou can complete tasks with the '-c [task name]' command.\033[0m\n\n";

    vec.push_back(tsk_temp);
    step = 0;
};

// marks a target task as complete
void complete_task(vector<s_task> &vec, int &step, string target)
{
    terminal_clear();

    if (vec.empty())
    {
        cout << "\033[1;31mYou have not added any tasks yet!\033[0m\n\n";
    }
    else
    {
        // for (int i = 0; i < vec.size(); i++)
        for (size_t i = 0; i < vec.size(); i++) // I was getting warnings about int.  It is just a warning, but technically the compiler wants a size_t here
        {
            if (vec.at(i).name == target)
            {
                vec.at(i).complete = true;
                cout << "\033[1;32mTask: " << vec.at(i).name << " is marked as complete!\033[0m\n\n";
                break;
            }
            else
            {
                cout << "\033[1;31mTask: " << target << " was not found.\033[0m\n\n";
                break;
            }
        }
    }
    step = 0;
}

// prints a given task
void print_task(vector<s_task> &vec, int index, string stat)
{
    cout << "Task: " << vec.at(index).name
         << "\n - Description: " << vec.at(index).desc
         << "\n - Priority: " << vec.at(index).priority
         << "\n - Due Date: "
         << to_string(vec.at(index).due_date.day) << "-"
         << to_string(vec.at(index).due_date.month) << "-"
         << to_string(vec.at(index).due_date.year)
         << "\n - Status: " << stat << "\n\n";
}

// used for viewing tasks, handles multiple sub commands for filtering
void view_task(vector<s_task> &vec, int &step, string target)
{
    int target_index{};
    string stat{};
    bool found{false};

    if (target == "-recent")
    {
        target_index = vec.size() - 1;
        found = locate_element(vec, target_index);
    }
    else if (target == "-all" && vec.size() > 0)
    {
        terminal_clear();
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec.at(i).complete)
            {
                stat = "Complete";
            }
            else
            {
                stat = "Incomplete";
            }
            print_task(vec, i, stat);
        }
    }
    else if (target == "-complete")
    {
        terminal_clear();
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec.at(i).complete)
            {
                stat = "Complete";
                print_task(vec, i, stat);
            }
        }
    }
    else if (target == "-incomplete")
    {
        terminal_clear();
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (!vec.at(i).complete)
            {
                stat = "Incomplete";
                print_task(vec, i, stat);
            }
        }
    }
    else
    {
        found = locate_element(vec, target, target_index);
    }

    if (found)
    {
        terminal_clear();
        if (vec.at(target_index).complete)
        {
            stat = "Complete";
        }
        else
        {
            stat = "Incomplete";
        }
        print_task(vec, target_index, stat);
    }

    step = 0;
};

// using std::sort to sort the tasks by priority and status
// lambda function to compare the given priorities in two given tasks and for space saving
void sort_task(vector<s_task> &vec, int &step, string target)
{ // Nice work here
    if (target == "-status")
    {
        sort(vec.begin(), vec.end(),
             [](const s_task &a, const s_task &b)
             {
                 return a.complete > b.complete;
             });
    }
    else if (target == "-priority")
    {
        sort(vec.begin(), vec.end(),
             [](const s_task &a, const s_task &b)
             {
                 return a.priority > b.priority;
             });
    }
    else
    {
        terminal_clear();
        cout << "Sorry, '" << target << "' is not a recognized argument, please try again.\n\n";
    }
    step = 0;
};

// prints the productivity report, lives in the main menu
void prod_rpt(vector<s_task> &vec, int &step)
{
    int completed_tasks{};
    int active_tasks{};

    cout << "Productivity Report"
         << "\n~~~~~~~~~~~~~~~~~~~"
         << "\nTotal tasks: " << vec.size();

    if (!vec.empty())
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (!vec.at(i).complete)
            {
                active_tasks++;
            }
            else if (vec.at(i).complete)
            {
                completed_tasks++;
            }
        }

        cout << "\nActive Tasks: " << active_tasks
             << "\nComplete Tasks: " << completed_tasks;
    }

    cout << "\n~~~~~~~~~~~~~~~~~~~\n";

    step = 0;
};