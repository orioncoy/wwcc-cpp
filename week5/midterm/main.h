#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>

/*
    Great job separating things into a .h file
*/

struct s_date
{
    int day;
    int month;
    int year;
};

struct s_task
{
    std::string name;
    std::string desc;
    int priority;
    s_date due_date;
    bool complete;
};

// interface related functions
void interface(std::vector<s_task> &tasks, int &step, std::string &target);
void help(int &step);
void init(std::vector<s_task> &tasks, int &step, std::string &target);
void terminal_clear();

// input handling
void inp_scrub(std::string &inp_temp, int &tsk_out);
void inp_scrub(std::string &inp_temp, int &tsk_out, int min, int max);
void inp_scrub(std::string &inp_temp, bool &tsk_out);
void inp_parser(std::vector<s_task> &vec, int &step, std::string usr_inp, std::string &target);
void s_token(std::vector<std::string> &p_vec, std::string usr_inp);

//
bool locate_element(std::vector<s_task> &vec, std::string target, int &target_index);
bool locate_element(std::vector<s_task> &vec, int target_index);

// command functions
void add_task(std::vector<s_task> &vec, int &step, std::string name);
void complete_task(std::vector<s_task> &vec, int &step, std::string target);
void view_task(std::vector<s_task> &vec, int &step, std::string target);
void sort_task(std::vector<s_task> &vec, int &step, std::string target);
void print_task(std::vector<s_task> &vec, int index, std::string stat);
void prod_rpt(std::vector<s_task> &vec, int &step);

#endif // MAIN_H
