#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct recipe {
    string name;
    string sing_count;
    string sstp_count;
    int iing_count;
    int istp_count;
    vector<string> ingredients;
    vector<string> steps;
};

// - ADD_RECIPE - // ----------------------------------- //

void add_recipe(vector<recipe> &ckbk) {
    recipe new_recipe;

    cout << "Name of recipe: ";
    getline(cin, new_recipe.name);
    cout << "Number of ingredients: ";
    getline(cin, new_recipe.sing_count);
    
    for (;;) {

    }

    cout << "Number of steps: ";
    getline(cin, new_recipe.sstp_count);

    for (;;) {

    }

    ckbk.push_back(new_recipe);
}

// - DISPLAY_ALL_RECIPE - // --------------------------- //

void disp_all_recipes(vector<recipe> &ckbk) {
    for (int i = 0; i < ckbk.size(); i++) {
        print_recipe(ckbk, i);
    }
}

// - SEARCH_RECIPE - // -------------------------------- //

recipe search_recipe(vector<recipe> &ckbk) {
    string target;
    for (int i = 0; i < ckbk.size(); i++) {
        if (ckbk.at(i).name == target) {
            return ckbk.at(i);
        }
    }
}

// - REMOVE_RECIPE - // -------------------------------- //

void rm_recipe(vector<recipe> &ckbk) {
    int target;
    ckbk.erase(ckbk.begin() + target);
}

// - SHOW_STATS - // ----------------------------------- //

void show_stats(vector<recipe> &ckbk) {
    int total_recipes = ckbk.size();
    double avg_recipe_ing;
    double avg_recipe_stp;


}

// - INPUT_HANDLING - // ----------------------------------------- //

void scrub(string &inp, int &ext) {
    try {
        ext = stoi(inp);
    } catch(const exception& e) {
        std::cerr << e.what() << '\n';
    }
    
};

// - GENERAL_FUNCS - // -------------------------------- //

void print_recipe(vector<recipe> &ckbk) {
    int target;
    recipe tar = ckbk.at(target);

    cout << "Recipe: " << tar.name;

    for (int i = 0; i < tar.iing_count; i++) {
        cout << "";
    }

    for (int i = 0; i < tar.istp_count; i++) {
        cout << "";
    }
}

void print_recipe(vector<recipe> &ckbk, int target) {
    int target;
    recipe tar = ckbk.at(target);

    cout << "Recipe: " << tar.name;

    for (int i = 0; i < tar.iing_count; i++) {
        cout << "";
    }

    for (int i = 0; i < tar.istp_count; i++) {
        cout << "";
    }
}

int get_recipe_index(vector<recipe> &ckbk) {
    string target;
    for (int i = 0; i < ckbk.size(); i++) {
        if (ckbk.at(i).name == target) {
            return i;
        }
    }
}

// - MAIN - // ----------------------------------------- //

int main() {
    vector<recipe> cookbook;
    string inp;
    int ctl_flow;
    bool app_loop;

    do {
        cout << "\nDYNAMIC RECIPE MANAGER"
         << "\n1. Add Recipe"
         << "\n2. Display All Recipes"
         << "\n3. Search Recipes"
         << "\n4. Remove Recipe"
         << "\n5. Show Statistics"
         << "\n6. Exit"
         << "\n"
         << "Enter an option: ";
        getline(cin, inp);

        scrub(inp, ctl_flow);

        switch (ctl_flow) {
        case 1:
            add_recipe(cookbook);
        case 2:
            disp_all_recipes(cookbook);
        case 3:
            search_recipe(cookbook);    
        case 4:
            rm_recipe(cookbook);
        case 5:
            show_stats(cookbook);
        case 6:
            app_loop = false;
        default:
            break;
        }
    
    } while (app_loop);

    return 0;
}