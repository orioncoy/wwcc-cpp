//-------------------------------+-------------+------------+
// Week 7 - Coding Assignment #2 | Calvin Losh | 05-26-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// - AUTHOR CLASS - // ------------------------------------- //
#pragma region ac

class c_author {
private:
    string name;
    int b_year;

public:
    c_author(string name, int b_year)
        : name(name), b_year(b_year) {}

    string get_name() {
        return name;
    }

    int get_birth_year() {
        return b_year;
    }
};

#pragma endregion ac

// - BOOK CLASS - // ------------------------------------- //
#pragma region bc

class c_book {
private:
    string title;
    c_author author;
    int pub_year;
    long isbn;

public:
    c_book(string title, c_author author, int pub_year, long isbn)
        : title(title), author(author), pub_year(pub_year), isbn(isbn) {}

    string get_title() const {
        return title;
    }

    c_author get_author() const {
        return author;
    }

    int get_publication_year() const {
        return pub_year;
    }

    long get_isbn() const {
        return isbn;
    }

    void print() const {

    }
};

#pragma endregion bc

// - LIBRARY CLASS - // ------------------------------------- //
#pragma region lc

class c_library {
private:
    string name;
    string address;
    vector<c_book> catalog;

public:
    c_library(string name, string address)
        : name(name), address(address) {}

    string get_name() const{
        return name;
    }

    string get_address() const {
        return address;
    }

    c_library& add_book(const c_book &book) {
        catalog.push_back(book);
        return *this;
    }

    void print_catalog() const;
    void print_info() const;
};

void c_library::print_info() const {
    cout << "\nName: " << name
         << "\nAddress: " << address << endl;
}

void c_library::print_catalog() const {
    print_info();
    cout << "\nLIBRARY CATALOG\n";
    for (int i = 0; i < catalog.size(); i++) {
        cout << "\n" << i + 1 << ": \"" << catalog.at(i).get_title() << "\" (" << to_string(catalog.at(i).get_publication_year()) << ")"
             << "\n   Author: " << catalog.at(i).get_author().get_name() << " (b. " << to_string(catalog.at(i).get_author().get_birth_year()) << ")"
             << "\n   ISBN: " << to_string(catalog.at(i).get_isbn()) << endl;
    }
}

#pragma endregion lc

// - MAIN - // ------------------------------------- //

int main() {
    cout << "\nLIBRARY MANAGEMENT SYSTEM"
         << "\n-=-=-=-=-=-=-=-=-=-=-=-=-"
         << endl;

    c_author scot_f("F. Scott Fitzgerald", 1896);
    c_author harp_l("Harper Lee", 1926);
    c_author geor_o("George Orwell", 1903);

    c_book gatsby("The Great Gatsby", scot_f, 1925, 9780743273565);
    c_book tkam("To Kill a Mockingbird", harp_l, 1960, 9780061120084);
    c_book b1984("1984", geor_o, 1949, 9780451524935);
    c_book anmlfrm("Animal Farm", geor_o, 1945, 9780451526342);

    c_library lib("Central City Library", "123 Main Street, Central City");

    lib.add_book(gatsby).add_book(tkam).add_book(b1984).add_book(anmlfrm);

    lib.print_catalog();

    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-";

    

    return 0;
}