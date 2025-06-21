#include "enemy.h"

#include <iostream>

using namespace std;

void enemy_stats(c_enemy enemy) {
    cout << "\n\n[" << enemy.get_name() << " - stats]"
         << "\n|-> Health [" << enemy.get_health() << "]"
         << "\n|-> Attack [" << enemy.get_attack() << "]";
}
