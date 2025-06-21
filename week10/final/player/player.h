#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "../area/area.h"

struct weapon {
    std::string name;
    int damage;
};

class c_player {
private:
    std::string name;
    int health = 5;
    int luck = 5;
    weapon equipped = {};
    areas current_location = areas::BURNT_VILLAGE;

public:
    c_player(std::string name) : name(name) {};

    // - GETTERS - //

    std::string get_name() {return name;}

    int get_health() {return health;}

    int get_luck() {return luck;}

    areas get_current_location() {return current_location;}

    weapon get_equipped() {return equipped;}
    //

    void equip_weapon(weapon weapon) {
        this->equipped = weapon;
    };

    void update_location(areas location) {
        this->current_location = location;
    }

    c_player take_damage(int damage) {
        this->health -= damage;
        return *this;
    }

    bool is_alive() {
        if (health > 0) {
            return true;
        } else {
            return false;
        }
    }
};

void player_stats(c_player player);

#endif //PLAYER_H
