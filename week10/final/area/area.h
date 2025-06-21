#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector>

#include "../enemy/enemy.h"

enum class area_type {
    SPAWN,
    FIGHT,
    PUZZLE,
    BOSS
};

enum class areas {
    BURNT_VILLAGE,
    UNTENDED_GRAVEYARD,
    FORGOTTEN_LABYRINTH,
    HALL_OF_EWYL
};

class c_area {
private:
    std::string name;
    area_type type;
    std::vector<c_enemy> area_enemies;

public:
    c_area(std::string name, area_type type) 
    : name(name), type(type) {};

    c_area add_enemy(std::vector<c_enemy> &enemies) {
        for (int i = 0; i < enemies.size(); i++) {
            area_enemies.push_back(enemies.at(i));
        } 
        return *this;       
    }

    c_area add_enemy(c_enemy enemy) {
        area_enemies.push_back(enemy);
        return *this;
    }
    c_enemy get_enemy(int index) {
        return area_enemies.at(index);
    }

    std::string get_name() {return name;};
};

std::array<c_area, 4> world_init();

#endif //AREA_H
