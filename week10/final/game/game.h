#ifndef GAME_H
#define GAME_H

#include "../player/player.h"
#include "../area/area.h"

enum class game_state {
    EXPLORE,
    COMBAT,
    GAME_OVER
};

void game_loop(bool &gameloop, c_player &player, std::array<c_area, 4> &map, game_state &state);

#endif //GAME_H

