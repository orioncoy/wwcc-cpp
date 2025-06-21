#include "area.h"
#include "../enemy/enemy.h"

#include <array>

using namespace std;

array<c_area, 4> world_init() {
    array<c_area, 4> map = {
        ([] {
            c_area burnt_village("The Burnt Village", area_type::SPAWN);

            burnt_village
                .add_enemy(c_enemy(enemy_type::UNDEAD, "undead guard"));

            return burnt_village;
        }()),

        //-------------------------//

        ([] {
            c_area untended_graveyard("The Untended Graveyard", area_type::FIGHT);
            
            untended_graveyard
                .add_enemy(c_enemy(enemy_type::SKELETON, "skully"))
                .add_enemy(c_enemy(enemy_type::SKELETON, "femur"))
                .add_enemy(c_enemy(enemy_type::UNDEAD, "rotjaw"))
                .add_enemy(c_enemy(enemy_type::UNDEAD, "moldy"));

            return untended_graveyard;
        }()),

        //-------------------------//

        ([] {
            c_area forgotten_labyrinth("A Forgotten Labyrinth", area_type::PUZZLE);

            forgotten_labyrinth
                .add_enemy(c_enemy(enemy_type::SKELETON, "labyrinth guide"));

            return forgotten_labyrinth;
        }()),

        //-------------------------//

        ([] {
            c_area hall_of_ewyl("The Hall of Ewyl", area_type::BOSS);

            hall_of_ewyl
                .add_enemy(c_enemy(enemy_type::BOSS, "Champion of the Abyss, Ewyl"));

            return hall_of_ewyl;
        }())
    };

    return map;
}