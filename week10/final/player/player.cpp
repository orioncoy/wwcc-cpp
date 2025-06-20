#include "player.h"

#include <iostream>

using namespace std;

void player_stats(c_player player) {
    cout << "\n#-[" << player.get_name() << " - stats]--------"

         << "\nHealth: [" << player.get_health() << "]";
    if (player.get_equipped().name != "") {
        cout << "\nEquiped: [" << player.get_equipped().name << "]";
    }
    cout << "\n#-----------------------";
}
