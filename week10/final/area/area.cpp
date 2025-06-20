#include "area.h"

#include <array>

std::array<c_area, 4> world_init() {
    std::array<c_area, 4> map = {
        ([] {
            c_area burnt_village("The Burnt Village", area_type::SPAWN);

            return burnt_village;
        }()),

        ([] {
            c_area untended_graveyard("The Untended Graveyard", area_type::FIGHT);

            return untended_graveyard;
        }()),

        ([] {
            c_area forgotten_labyrinth("A Forgotten Labyrinth", area_type::PUZZLE);

            return forgotten_labyrinth;
        }()),

        ([] {
            c_area hall_of_ewyl("The Hall of Ewyl", area_type::BOSS);

            return hall_of_ewyl;
        }())
    };

    return map;
}