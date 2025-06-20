#ifndef PROD_H
#define PROD_H

#include <string>

class c_product {
private:
    int id;
    int qty;
    float price;
    std::string name;
    
public:
    c_product(int id, int qty, float price, std::string name)
        : id(id), qty(qty), price(price), name(name) {};

    // - INLINE FUNCTIONS - // ---------------- //

    int get_id() {
        return id;
    };

    int get_quantity() {
        return qty;
    };

    float get_price() {
        return price;
    };

    std::string get_name() {
        return name;
    };

    // - FUNCTION PROTOS - // ---------------- //

    void print_prod();

};

#endif //PROD_H