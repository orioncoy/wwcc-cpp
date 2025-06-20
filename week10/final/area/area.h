#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector>

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

public:
    c_area(std::string name, area_type type) : name(name), type(type) {};

    std::string get_name() {return name;};
};

std::array<c_area, 4> world_init();

#endif //AREA_H
