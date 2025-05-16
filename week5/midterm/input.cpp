//------------------+-------------+------------+
// Week 5 - Midterm | Calvin Losh | 12-05-2025 |
//------------------+-------------+------------+
// input.cpp - handling input scrubbing and parsing

#include <sstream>

#include "main.h"

using namespace std;

// input scrubbing for int inputs
void inp_scrub(string &inp_temp, int &tsk_out) {
    try {
        tsk_out = stoi(inp_temp);
        inp_temp = {};
    } catch(const exception& e) {
        cerr << e.what() << '\n';
    }
}

// input scrubbing for int inputs with a specified range
void inp_scrub(string &inp_temp, int &tsk_out, int min, int max) {
    inp_scrub(inp_temp, tsk_out);

    //checks to see if the input is within range and scrubs to input again for good measure
    while (tsk_out < min || tsk_out > max) {
        cout << "\033[1;31mThe input exceeds the specified range or is invalid,"
                "\nplease enter a whole number between "
             << to_string(min) << " and " << to_string(max) << ": \033[0m";
        getline(cin, inp_temp);
        inp_scrub(inp_temp, tsk_out);
    }
}

// input scrubbing for bool inputs
void inp_scrub(string &inp_temp, bool &tsk_out) {
    if (inp_temp == "True") {
        tsk_out = true;
        inp_temp = {};
    } else if (inp_temp == "False") {
        tsk_out = false;
        inp_temp = {};
    } else {
        // error message
        inp_temp = {};
    }
}

// checks if the target in a command is there and prompts user if it is empty
void target_scrub(vector<string> &p_vec, string &usr_inp, string target) {
    if (target.empty()) {
        cout << "\033[1;31mYou must provide an argument with this command, try again\033[0m\n> ";
        getline(cin, usr_inp);
        s_token(p_vec, usr_inp);
    }
}

// takes in a string and a vector by reference, tokenizes the string and assigns each token to
// an element in the vector iteratively
void s_token(vector<string> &p_vec, string usr_inp) {
    stringstream s(usr_inp);
    string word{};
    while (s >> word) {
        p_vec.push_back(word);
    }
}

// parses the user input by tokenizing the vector
void inp_parser(vector<s_task> &vec, int &step, string usr_inp, string &target) {
    vector<string> parsed_vec;

    s_token(parsed_vec, usr_inp);

    while (parsed_vec.empty()) {
        cout << "\033[1;31mNo input provided, please try again.\033[0m\n> ";
        getline(cin, usr_inp);
        s_token(parsed_vec, usr_inp);
    }

    string cmd = parsed_vec.at(0);

    // bypass for no argument commands
    if (cmd == "-h" || cmd == "-q" || cmd != "-a" && cmd != "-c" && cmd != "-v" && cmd != "-s") {} 
    else if (parsed_vec.size() == 2) {
        // assigns command argument to target
        target = parsed_vec.at(1);
    } else if (parsed_vec.size() < 2) {
        // if the command lacks an argument, prompts user to enter one
        while (parsed_vec.size() < 2) {
            cout << "\033[1;31mYou must include an argument with your command, " << cmd << " [argument]. "
                    "Try again\033[0m\n> ";
            parsed_vec = {};
            getline(cin, usr_inp);
            s_token(parsed_vec, usr_inp);
        }
        target = parsed_vec.at(1);
    } else {
        // if more than one argument is present, prompts user to 
        // re-enter command with only one argument
        while (parsed_vec.size() > 2) {
            cout << "\033[1;31mOnly include one argument with your command, " << cmd << " [argument]. "
                    "Try again\033[0m\n> ";
            parsed_vec = {};
            getline(cin, usr_inp);
            s_token(parsed_vec, usr_inp);
        }
        target = parsed_vec.at(1);
    }

    if (cmd == "-a") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 1;
    } else if (cmd == "-q") {
        step = 2;
    } else if (cmd == "-c") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 3;
    } else if (cmd == "-v") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 4;
    } else if (cmd == "-s") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 5;
    }else if (cmd == "-h") {
        step = 6;
    } else {
        terminal_clear();
        cout << "\033[1;31mSorry, '"  << cmd << "' is not a recognized command\033[0m\n\n";
    }
}
