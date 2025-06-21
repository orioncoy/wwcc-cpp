#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

enum class enemy_type {
    UNDEAD,
    SKELETON,
    BOSS
};

class c_enemy {
private:
    enemy_type type;
    std::string name;
    int health;
    int attack;

public:
    c_enemy(enemy_type type, std::string name)
    : type(type), name(name) {
        switch (type) {
        case enemy_type::UNDEAD:
            this->health = 5;
            break;
        case enemy_type::SKELETON:
            this->health = 5;
            break;
        case enemy_type::BOSS:
            this->health = 5;
            this->attack = 2;
            break;
        default:
            break;
        }
    }

    int get_attack() {
        return attack;
    }
    enemy_type get_enemy_type() {
        return type;
    }
    std::string get_name() {
        return name;
    }
    int get_health() {
        return health;
    }

    void take_damage(int damage) {
        this->health -= damage;
    }

    bool is_alive() {
        if (health > 0) {
            return true;
        } else {
            return false;
        }
    }
};

void enemy_stats(c_enemy enemy);

#endif //ENEMY_H
