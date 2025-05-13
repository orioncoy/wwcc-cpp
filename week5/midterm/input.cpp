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
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
};

// input scrubbing for int inputs with a specified range
void inp_scrub(string &inp_temp, int &tsk_out, int min, int max) {
    inp_scrub(inp_temp, tsk_out);

    //checks to see if the input is within range and scrubs to input again for good measure
    while (tsk_out < min || tsk_out > max) {
        cout << "The input exceeds the specified range, please enter a number between "
             << to_string(min) << " and " << to_string(max);
        getline(cin, inp_temp);
        inp_scrub(inp_temp, tsk_out);
    }
};

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
};

void target_scrub(vector<string> &p_vec, string &usr_inp, string target) {
    if (target.empty()) {
        cout << "You must provide an argument with this command, try again\n>";
        getline(cin, usr_inp);
        s_token(p_vec, usr_inp);
    }
}

void s_token(vector<string> &p_vec, string usr_inp) {
    stringstream s(usr_inp);
    string word{};
    while (s >> word) {
        p_vec.push_back(word);
    }
}

// parses the user input by tokenizing the vector
void inp_parser(vector<s_task> &vec, int &step, string usr_inp) {
    vector<string> parsed_vec;

    s_token(parsed_vec, usr_inp);

    while (parsed_vec.empty()) {
        cout << "No input provided, please try again.\n> ";
        getline(cin, usr_inp);
        s_token(parsed_vec, usr_inp);
    }

    string cmd = parsed_vec.at(0);
    string target = (parsed_vec.size() > 1) ? parsed_vec.at(1) : "";

    while (parsed_vec.size() < 2) {
            cout << "You must include a name with your task, -a [task name here]. "
                    "Try again\n> ";
            getline(cin, usr_inp);
            s_token(parsed_vec, usr_inp);
    }

    if (cmd == "-a") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 1;
    } else if (cmd == "-r") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 2;
    } else if (cmd == "-u") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 3;
    } else if (cmd == "-v") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 4;
    } else if (cmd == "-s") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 5;
    } else if (cmd == "-pr") {
        target_scrub(parsed_vec, usr_inp, target);
        step = 6;
    } else if (cmd == "-h") {
        step = 7;
    } else {
        cout << "Sorry, "  << cmd << " is not a recognized command";
    }

    if (step == 7) {
        interface(vec, step, "");
    } else {
        interface(vec, step, target);
    }
}
