/* 
Interactive Story Game - DimSoles
Author: Calvin Losh
Date: 06-21-2025
*/

#include <iostream>
#include <string>
#include <array>

#include "cmd/commands.h"
#include "game/game.h"
#include "player/player.h"

int main() {
    using namespace std;

    game_state state = game_state::EXPLORE;

    string input{};
    bool gameloop = true;

    array<c_area, 4> map = world_init();

    cout << "\nWelcome to DimSoles!"
         << "\nPress any key to start the game";
    getline(cin, input);

    screen_clear();

    cout << "\nTo get started, please enter your players name\n> ";
    getline(cin, input);

    c_player player(input);

    cout << "\n" << player.get_name() << " wakes up in a pile of rubble, lacking any memory of what happened."
            << "\nAfter standing up, " << player.get_name() << " sees nothing but a burnt village.";

    game_loop(gameloop, player, map, state);
}