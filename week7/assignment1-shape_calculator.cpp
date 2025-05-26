//-------------------------------+-------------+------------+
// Week 7 - Coding Assignment #1 | Calvin Losh | 05-26-2025 |
//-------------------------------+-------------+------------+

#include <iostream>
#include <math.h>

using namespace std;

// - RECTANGLE CLASS - // ------------------------------------- //

class rectangle {
private:
    double length;
    double width;

public:
    rectangle(double length, double width) : length(length), width(width) {}

    double get_length() const {
        return length;
    }

    double get_width() const {
        return width;
    }

    double get_area() const {
        return width * length;
    }

    rectangle& resize(double l, double w) {
        length = l;
        width = w;
        return *this;
    }

    void print() const;
    void print(bool show) const;
};

void rectangle::print() const{
    cout << "\n\nRectangle Information:"
         << "\n - Length: " << rectangle::get_length()
         << "\n - Width: " << rectangle::get_width()
         << "\n - Area: " << rectangle::get_area();
}

void rectangle::print(bool show) const{
    if (!show) {
        rectangle::print();
    } else {
        cout << "\n\nDetailed Rectangle Calculations:"
             << "\n - Area: " << rectangle::get_length() << " x " << rectangle::get_width() << " = " << rectangle::get_area();
    }
}

 // - CIRCLE CLASS - // ------------------------------------- //

class circle {
private:
    double radius;

public:
    circle(double radius) : radius(radius) {}

    double get_radius() const {
        return radius;
    }

    double get_circumference() const {
        return 2 * M_PI * radius;
    }

    double get_area() const{
        return M_PI * pow(radius, 2);
    }

    circle& resize(double r) {
        radius = r;
        return *this;
    }

    void print() const;
    void print(bool show) const;
};

void circle::print() const {
    cout << "\n\nCircle Information: "
         << "\n - Radius: " << to_string(circle::get_radius())
         << "\n - Circumference: " << to_string(circle::get_circumference())
         << "\n - Area: " << to_string(circle::get_area());
}

void circle::print(bool show) const {
    if (!show) {
        circle::print();
    } else {
        cout << "\n\nDetailed Circle Calculations:"
             << "\n - Circumference: 2 x pi x " << circle::get_radius() << " = " << circle::get_circumference()
             << "\n - Area: pi x " << circle::get_radius() << "^2 = " << circle::get_area();
    }
}

// - MAIN - // ------------------------------------- //

int main() {
    circle circ_1(5);
    rectangle rect_1(5, 7);

    cout << "\nSHAPE CALCULATOR:";

    circ_1.print();
    rect_1.print();
    circ_1.print(true);
    rect_1.print(true);

    cout << "\n\nMethod Chain Example"
         << "\n\nOriginal Rectangle: ";

    rect_1.print();

    cout << "\n\nUpdated Rectangle: ";

    rect_1.resize(3, 8).print();

}