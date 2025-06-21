#include "player.h"

#include <iostream>

using namespace std;

void player_stats(c_player player) {
    cout << "\n\n[" << player.get_name() << " - stats]"

         << "\n|-> Health [" << player.get_health() << "]";
    if (player.get_equipped().name != "") {
        cout << "\n|-> Equiped [" << player.get_equipped().name << "]"
             << "\n|   |-> Damage [" << player.get_equipped().damage << "]";
    }
}
