#include <iostream>


#include "../cmd/commands.h"
#include "game.h"

using namespace std;

void play_burnt_village(bool &gameloop, c_player &player, game_state &state) {
    screen_clear();
    player_stats(player);

    int iinput;
    bool binput;

    vector<string> options_1 = {
        "Explore the village",
        "Escape the village",
        "Look for items"
    };

    cout << "\nWhat would you like to do?";
    int i = 0;
    for (const auto &option : options_1) {
        cout << "\n" << i + 1 << ". " << options_1[i];
        i++;
    }
    cout << "\n> ";
    iinput = selection_scrub(1, 3);

    switch (iinput) {
        case 1:
            screen_clear();
            player_stats(player);
            cout << "\nYou explore the village, finding little to nothing"
                 << "\nEventually you come across partially destroyed barracks"
                 << "\nWould you like to explore the barracks? \n(y/n) > ";
            binput = selection_scrub();
            if (binput) {
                cout << "\nWhile searching the barracks, you find a rusty sword!"
                     << "\nWould you like to take the sword? \n(y/n) > ";
                binput = selection_scrub();
                if (binput) {
                    weapon rusty_sword = {"Rusty sword", 5};
                    player.equip_weapon(rusty_sword);
                    cout << "You have equipped the rusty sword!";
                    options_1.erase(options_1.begin() + 0);
                }
            }
            break;
        case 2:
            screen_clear();
            player_stats(player);
            cout << "\nYou look around and spot a path leading out of the village";
            if (player.get_equipped().name == "") {
                cout << "\nBeyond the path you maybe see something move"
                     << "\nreflexively you reach for your weapon but there is nothing"
                     << "\nYou are unarmed, proceed? \n(y/n) > ";
                binput = selection_scrub();
                if (binput) {
                    cout << "\nAs you wish.";
                    player.update_location(areas::UNTENDED_GRAVEYARD);
                    break;
                }
            }
            break;
        case 3:
            screen_clear();
            player_stats(player);
            cout << "\nAs you look around for any items you spot a corpse holding a polearm"
                 << "\nWould you like to equip the polearm?\n(y/n) > ";
            binput = selection_scrub();
            if (binput) {
                state = game_state::COMBAT;
                cout << "\nYou lean over to grab the weapon and the corpse moves"
                     << "\nIn a snap, the pole arm is thrust at you but you dodge just in time"
                     << "\n[You have entered combat, proceed with caution!]";
                do {
                    screen_clear();
                    player_stats(player);
                    cout << "\nIt is your turn, what would you like to do?";
                    if (player.get_equipped().name != "") {
                        cout << "(You are currently unarmed!)";
                    }
                    cout << "\n1. Attack " << "(" << player.get_equipped().damage * 10 << "% of hitting)"
                         << "\n2. Flee " << "(" << player.get_luck() * 20 << "% of fleeing)"
                         << "\n3. Talk to the poor guy " << "(as your not-a-lawyer lawyer, this is ill-advised)"
                         << "\nEnter an option > ";

                    iinput = selection_scrub(1, 3);

                    switch (iinput) {
                        case 1:
                            cout << "\nAs you go in for an attack, you are impaled with the polearm and die instantly";
                            state = game_state::GAME_OVER;
                            break;
                        case 2:
                            cout << "\nYou were able to get away without a hitch, the undead soldier sits back down.";
                            state = game_state::EXPLORE;
                            break;
                        case 3:
                            cout << "\nYou lower your fists and ask the guy how hes doing, to your surprise"
                                 << "\nhe responds and you guys chat it up. Turns out he was a guard and got"
                                 << "\ncursed by some pissed off ancient champion. He can't give you his polearm"
                                 << "\nbut advises you check out the barracks around the corner for any left over"
                                 << "\nweapons.";
                            state = game_state::EXPLORE;
                            break;
                        default:
                            break;
                    }

                } while (state == game_state::COMBAT);
            }
            break;
        default:
            break;
    }
}

void play_untended_graveyard(bool &gameloop, c_player &player, game_state &state) {
    screen_clear();
    player_stats(player);

    int iinput;
    bool binput;
}

void play_forgotten_labyrinth(bool &gameloop, c_player &player, game_state &state) {
    screen_clear();
    player_stats(player);

    int iinput;
    bool binput;
}

void play_hall_of_ewyl(bool &gameloop, c_player &player, game_state &state) {
    screen_clear();
    player_stats(player);

    int iinput;
    bool binput;
}

void game_loop(bool &gameloop, c_player &player, std::array<c_area, 4> &map, game_state &state) {
    using namespace std;

    while (gameloop && state != game_state::GAME_OVER) {
        switch (player.get_current_location()) {

            case areas::BURNT_VILLAGE:
                cout << "\nWelcome to " << map[0].get_name();
                play_burnt_village(gameloop, player, state);
                break;

            case areas::UNTENDED_GRAVEYARD:
                cout << "\nWelcome to " << map[1].get_name();
                play_untended_graveyard(gameloop, player, state);
                break;

            case areas::FORGOTTEN_LABYRINTH:
                cout << "\nWelcome to " << map[2].get_name();
                play_forgotten_labyrinth(gameloop, player, state);
                break;

            case areas::HALL_OF_EWYL:
                cout << "\nWelcome to " << map[3].get_name();
                play_hall_of_ewyl(gameloop, player, state);
                break;

            default:
                break;
        }
    }
}
