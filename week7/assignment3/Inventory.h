#ifndef INV_H
#define INV_H

#include <vector>
#include <string>

#include "Product.h"

class c_inventory {
private:
    std::vector<c_product> inventory;

public:
    // - INLINE FUNCTIONS - // ---------------- //

    c_inventory& add_product(c_product prod) {
        inventory.push_back(prod);
        return *this;
    }

    c_product get_product(int index) const {
        return inventory.at(index);
    }

    int inv_size() {
        return inventory.size();
    }

    // - FUNCTION PROTOS - // ---------------- //

    void print_inv();

    void update_prod(c_product);

    c_product find_prod(std::string inp);


};

#endif //INV_H