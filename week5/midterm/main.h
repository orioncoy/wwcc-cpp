#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>


struct s_date {
    int day;
    int month;
    int year;
};

struct s_task {
    std::string name;
    std::string desc;
    int priority;
    s_date due_date;
    bool complete;
};

// interface related functions
void interface(std::vector<s_task> &tasks, int &step, std::string target);
void help(std::vector<s_task> &vec, int &step);
void init(std::vector<s_task> &tasks, int &step);
void terminal_clear();

// input handling
void inp_scrub(std::string &inp_temp, int &tsk_out);
void inp_scrub(std::string &inp_temp, int &tsk_out, int min, int max);
void inp_scrub(std::string &inp_temp, bool &tsk_out);
void inp_parser(std::vector<s_task> &vec, int &step, std::string usr_inp);
void s_token(std::vector<std::string> &p_vec, std::string usr_inp);

//
int  locate_element(std::vector<s_task> &vec, std::string target);
void inp_clean();

// command functions
void add_task(std::vector<s_task> &vec, int &step, std::string name);
void remove_task(std::vector<s_task> &vec, int &step, std::string target);
void update_task(std::vector<s_task> &vec, int &step, std::string target);
void print_task(std::vector<s_task> &vec, int &step, std::string target);
void sort_task(std::vector<s_task> &vec, int &step);
void prod_rpt(std::vector<s_task> &vec, int &step);


#endif //MAIN_H
