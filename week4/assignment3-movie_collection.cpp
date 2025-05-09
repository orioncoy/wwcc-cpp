//-------------------------------+-------------+------------+
// Week 4 - Coding Assignment #3 | Calvin Losh | 08-05-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Movie {
    string title;
    string director;
    string genre;
    int year;
    int duration;
    double rating;
};

//using an overloaded function to handle input scrubbing
void scrub(string &temp, string &target) {
    target = temp;
    temp = {};
}
void scrub(string &temp, int &target) {
    try {
        target = stoi(temp);
        temp = {};
    } catch(const exception& e) {
        cout << "Please try again with the proper formatting: ";
        temp = {};
        cin >> temp;
        scrub(temp, target);
    }
}
void scrub(string &temp, double &target) {
    try {
        target = stod(temp);
        temp = {};
    } catch(const exception& e) {
        cout << "Please try again with the proper formatting: ";
        temp = {};
        cin >> temp;
        scrub(temp, target);
    }
}

int main() {
    Movie movie[3]{};
    string temp{};

    int arr_len{sizeof(movie) / sizeof(movie[0])};
    int longest{0};
    int inp_year{};
    double rate_tot{};

    cout << "\nMOVIE COLLECTION MANAGER"
         << "\n------------------------";

    for (int i = 0; i < arr_len; i++) {
        cout << "\nInformation for movie #" << i + 1
             << "\nTitle: ";
        cin >> temp;
        scrub(temp, movie[i].title);
        cout << "Director: ";
        cin >> temp;
        scrub(temp, movie[i].director);
        cout << "Genre: ";
        cin >> temp;
        scrub(temp, movie[i].genre);
        cout << "Year: ";
        cin >> temp;
        scrub(temp, movie[i].year);
        cout << "Duration (in minutes): ";
        cin >> temp;
        scrub(temp, movie[i].duration);
        cout << "Rating (out of 10): ";
        cin >> temp;
        scrub(temp, movie[i].rating);
        temp = {};
    }

    cout << "\n\nYOUR MOVIE COLLECTION:"
         << "\n----------------------";

    for (int i = 0; i < arr_len; i++) {
        cout << "\n" << i + 1 << ". " << movie[i].title << " (" << movie[i].year << ")"
             << "\n   Director: " << movie[i].director
             << "\n   Duration: " << movie[i].duration << " minutes"
             << "\n   Rating: " << movie[i].rating << "/10"
             << "\n   Genre: " << movie[i].genre;
    }

    for (int i = 0; i < arr_len; i++) {
        rate_tot += movie[i].rating;
        if (movie[i].duration > movie[longest].duration) {
            longest = i;
        }
    }

    cout << "\nCollection stats:"
         << "\nAverage rating: " << rate_tot/arr_len << "/10"
         << "\nLongest movie: " << movie[longest].title << " (" << movie[longest].duration << " minutes)";

    cout << "\n\nEnter a year to find movies released after that year: ";
    cin >> temp;
    scrub(temp, inp_year);

    cout << "\nMovies";
    for (int i = 0; i < arr_len; i++) {
        if (movie[i].year > inp_year) {
            cout << "\n - " << movie[i].title << " (" << movie[i].year << ")";
        }
    }

    return 0;
}