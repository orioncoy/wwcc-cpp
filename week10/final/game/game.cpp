#include <iostream>
#include <cstdlib>

#include "../area/area.h"
#include "../enemy/enemy.h"
#include "../cmd/commands.h"

#include "game.h"

using namespace std;

void play_burnt_village(bool &gameloop, c_player &player, game_state &state, std::array<c_area, 4> &map) {
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
            cout << "\nYou explore the village, finding little to nothing"
                 << "\nEventually you come across partially destroyed barracks"
                 << "\nWould you like to explore the barracks? \n(y/n) > ";
            binput = selection_scrub();
            if (binput) {
                cout << "\nWhile searching the barracks, you find a rusty sword!"
                     << "\nWould you like to take the sword? \n(y/n) > ";
                binput = selection_scrub();
                if (binput) {
                    weapon rusty_sword = {"Rusty sword", 3};
                    player.equip_weapon(rusty_sword);
                    cout << "\nYou have equipped the rusty sword!";
                    options_1.erase(options_1.begin() + 0);
                }
            }
            break;
        case 2:
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
            cout << "\nHow would you like to proceed?"
                 << "\n1. Follow the path out of the village"
                 << "\n2. Wait before leaving\n> ";
            iinput = selection_scrub(1, 2);
            switch (iinput) {
                case 1:
                    cout << "\nYou proceed down the path...";
                    player.update_location(areas::UNTENDED_GRAVEYARD);
                    break;
                case 2:
                    break;
                default:
                    break;
            }
            break;
        case 3:
            cout << "\nAs you look around for any items you spot a corpse holding a polearm"
                 << "\nWould you like to equip the polearm?\n(y/n) > ";
            binput = selection_scrub();
            if (binput) {
                state = game_state::COMBAT;
                cout << "\nYou lean over to grab the weapon and the corpse moves"
                     << "\nIn a snap, the pole arm is thrust at you but you dodge just in time"
                     << "\n\n[You have entered combat, proceed with caution!]";
                do {

                    cout << "\nIt is your turn, what would you like to do?";
                    if (player.get_equipped().name == "") {
                        cout << "\n(You are currently unarmed!)";
                    }
                    cout << "\n1. Attack " << "(" << player.get_equipped().damage * 20 << "% of hitting)"
                         << "\n2. Flee " << "(" << player.get_luck() * 20 << "% of fleeing)"
                         << "\n3. Talk to the poor guy " << "(as your not-a-lawyer lawyer, this is ill-advised)\n> ";

                    iinput = selection_scrub(1, 3);

                    switch (iinput) {
                        case 1:
                            if (player.get_equipped().name == "") {
                                cout << "\nAs you go in for an attack, you are impaled with the polearm and die instantly";
                                state = game_state::GAME_OVER;
                            } else {
                                cout << "\nYou easily take down the undead guard with your weapon";
                                state = game_state::EXPLORE;
                            }
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

void play_untended_graveyard(bool &gameloop, c_player &player, game_state &state, std::array<c_area, 4> &map) {
    int iinput;
    bool binput;

    cout << "\nYou approach the graveyard and see an overgrown, some might even say, untended, graveyard"
         << "\nIn front of you, it appears a skeleton is weeping at a grave,"
         << "\nYour move."
         << "\n1. Approach the skeleton"
         << "\n2. Ignore the skeleton and look around"
         << "\n3. Retreat back to the village\n> ";
    iinput = selection_scrub(1, 3);

    switch(iinput) {
        case 1:
            cout << "\nYou approach the skeleton and before you can say anything it looks at you and grins"
                 << "\n[You have entered combat!]\n";
            state = game_state::COMBAT;
            cout << "\nYou are struck on the back with a blunt object and fall over onto the skeleton in front of you, crushing it."
                 << "\nAfter rolling over, you see another skeleton, visibly pissed off with its arms in the air."
                 << "\nFemur: c'mon skully! you were supposed to stab him!\n";
            do {
                cout << "\nIt is your turn, what would you like to do?";
                if (player.get_equipped().name == "") {
                    cout << "\n(You are currently unarmed!)";
                }
                cout << "\n1. Attack " << "(" << player.get_equipped().damage * 10 << "% of hitting)"
                     << "\n2. Flee " << "(" << player.get_luck() * 10 << "% of fleeing)\n> ";
                iinput = selection_scrub(1, 2);
                    switch (iinput) {
                        case 1:
                            if (player.get_equipped().name == "") {
                                cout << "\nYou dash at Femur, tackling his legs, causing him to fall apart and die instantly";
                                state = game_state::EXPLORE;
                                break;
                            } else {
                                cout << "\nYou grab your sword and slash at Femur's femur, cutting off his leg as the rest of his body crumbles\n";
                                state = game_state::EXPLORE;
                                break;
                            }
                        case 2:
                            if (player.get_luck() > 4) {
                                cout << "\nYou made it out alive!";
                                state = game_state::EXPLORE;
                                break;
                            } else {
                                cout << "\nAs you try to make a break for it, Femur grabs your foot and throws you a solid 60ft into the air, ending your life";
                                state = game_state::GAME_OVER;
                                break;
                            }
                        default:
                            break;
                    }
            } while (state == game_state::COMBAT);

            cout << "\nYou hear some shouting from the distance"
                 << "\n\nRotjaw: What is going on over there?"
                 << "\nYou see two undead guards approach you"
                 << "\n\nRotjaw: Man, I'm sorry, Skully and Femur are jerks, they hate us 'skinwalkers' and especially warmbloods"
                 << "\nMoldy: Yeah don't mind them, while technically dead, they'll be back in a day or two, unfortunately"
                 << "\nRotjaw: Say, we have a favor to ask, what do you say? \n(y/n) > ";
            binput = selection_scrub();
            if (binput) {
                cout << "\nRotjaw: That is great, we need help breaking this curse but only a warmblood like you can do it"
                     << "\nMoldy: If you head through those doors covered in vines there, you'll be on your way to break it"
                     << "\n\nHead through the door to break the curse?\n(y/n) > ";
                binput = selection_scrub();
                if (binput) {
                    cout << "\nYou head to the door and push past the vines, entering the forgotten labyrinth";
                    player.update_location(areas::FORGOTTEN_LABYRINTH);
                }
            }


            break;
        case 2:
            cout << "\nYou walk around the skeleton and before you know it another skeleton dashes from the path you just came from"
                 << "\nIn its haste, it trips on a rock and crashes right into the weeping skeleton, causing both of them to turn into a pile of bones"
                 << "\nWith the commotion, you catch the attention of two undead guards sitting around a unlit fir pit"
                 << "\nThey wave at you, what do you do?"
                 << "\n1. Run away"
                 << "\n2. Wave back and approach them\n> ";
        
            iinput = selection_scrub(1, 2);
            switch (iinput) {
                case 1:
                    cout << "\nYou frantically look for a way to run, you see two options"
                         << "\n1. The path back to the village"
                         << "\n2. An old door covered in vines";
                    iinput = selection_scrub(1, 2);
                    switch (iinput) {
                        case 1:
                            player.update_location(areas::BURNT_VILLAGE);
                            break;
                        case 2:
                            player.update_location(areas::FORGOTTEN_LABYRINTH);
                            cout << "\nYou sprint through the graveyard and shoulder slam the door, busting it open.";
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    cout << "\nAs you wave back, they gesture you over and you oblige"
                         << "\nRotjaw: Hey, I see Femur and Skully were giving you a hard time, sorry about that"
                         << "\nMoldy: Yeah they really don't like us 'skinwalkers' anyways, they'll be fine by the way, cursed like the rest of us"
                         << "\nRotjaw: Speaking of the curse, a Warmblood like you could give a hand, what do you say?\n(y/n) > ";
                    binput = selection_scrub();
                    if (binput) {
                        cout << "\nRotjaw: Great! You see that vine covered door over there? Head on in and you'll be doing us all a huge favor"
                             << "\nProceed? (y/n)";
                        binput = selection_scrub();
                        if (binput) {
                            player.update_location(areas::FORGOTTEN_LABYRINTH);
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case 3:
            player.update_location(areas::BURNT_VILLAGE);
            break;
        default:
            break;
    }
}

void play_forgotten_labyrinth(bool &gameloop, c_player &player, game_state &state, std::array<c_area, 4> &map) {
    int iinput;
    bool binput;
    auto attempts_remaining = 2;

    cout << "\nYou walk into a large circular room, three large statues of godly figures stand opposed to you"
         << "\nOn a round table in the middle of the room lies a skeletons head, Yapthorn, he speaks."
         << "\n\n[" << attempts_remaining << "] attempts remaining. Fail and you perish.";

    state = game_state::PUZZLE;

    cout << "\n\n'One lies... one tells the truth... one merely believes'"
         << "\nEach statue bears an inscription on its base:"
         << "\n1. Serwin, the Veiled Confessor"
         << "\n   \"The door will open if you listen to me.\""
         << "\n2. Oreth, the Lantern-Bearer"
         << "\n   \"Kaelmor lies.\""
         << "\n3. Kaelmore, the Mocker Below"
         << "\n   \"Serwin speaks the truth.\""
         << "\nListen to: ";

    do {
        if (attempts_remaining == 0) {
            cout << "\nYapthorn: You have failed Ewyl."
                 << "\nThe room slowly fills up with a purple mist and your vision fades";
            state = game_state::GAME_OVER;
        } else {
            iinput = selection_scrub(1, 3);
            switch (iinput) {
                case 1:
                    attempts_remaining--;
                    cout << "\nYapthorn: You are incorrect.\n[" << attempts_remaining << "] attempts remaining.\nListen to: ";
                    break;
                case 2:
                    cout << "\nYapthorn: Correct. You may proceed to the Hall of Ewyl.";
                    player.update_location(areas::HALL_OF_EWYL);
                    state = game_state::EXPLORE;
                    break;
                case 3:
                    attempts_remaining--;
                    cout << "\nYapthorn: You are incorrect.\n[" << attempts_remaining << "] attempts remaining.\nListen to: ";
                    break;
                default:
                    break;
            }
        }
    } while (state == game_state::PUZZLE);
}

void play_hall_of_ewyl(bool &gameloop, c_player &player, game_state &state, std::array<c_area, 4> &map) {
    int iinput;
    bool binput;

    c_enemy ewyl = map[3].get_enemy(0);

    int chance;

    screen_clear();

    state = game_state::COMBAT;

    cout << "\n\"You have entered the Hall of Ewyl.\" A void overhead booms \"there is no going back\""
         << "\n\nA long, dimly lit hallway is all that stands in front of you, looking behind you, there is only more hallway"
         << "\nThe door you had just walked through is gone"
         << "\n\nIts booming voice returns, \"Walk!\""
         << "\n\nAn invisible force pushes you down the hall, almost as though the hall is moving around you"
         << "\nIt keeps accelerating and in a moment it stops in front of a large pair of iron reinforced doors"
         << "\n\n\"Enter!\" the doors slowly creek open to a dark throne room"
         << "\n\nA person sits at the throne, they raise their hand and command in that familiar booming voice";
// something something i like a fair fight

    do {
        srand(time(0));
        player_stats(player);
        enemy_stats(ewyl);
        cout << "\nIt is Ewyl's turn";
        chance = 1 + rand() % ewyl.get_attack();
        cout << "\nEwyl attacks you for " << chance
             << "\n\nIt is your turn"
             << "\nAttack? (y/n) > ";
        player.take_damage(chance);
        if (!player.is_alive()) {state = game_state::GAME_OVER;}
        binput = selection_scrub();
        if (binput && state != game_state::GAME_OVER) {
            chance = 1 + rand() % player.get_equipped().damage - 1;
            cout << "You attack Ewyl for " << chance;
            ewyl.take_damage(chance);
            if (!ewyl.is_alive()) {
                state = game_state::WIN;
            }
        }


    } while (state == game_state::COMBAT);
}

void game_loop(bool &gameloop, c_player &player, std::array<c_area, 4> &map, game_state &state) {
    using namespace std;

    while (gameloop && state != game_state::GAME_OVER && state != game_state::WIN) {
        switch (player.get_current_location()) {

            case areas::BURNT_VILLAGE:
                cout << "\n\n- " << map[0].get_name() << " -";
                play_burnt_village(gameloop, player, state, map);
                break;

            case areas::UNTENDED_GRAVEYARD:
                cout << "\n\n- " << map[1].get_name() << " -";
                play_untended_graveyard(gameloop, player, state, map);
                break;

            case areas::FORGOTTEN_LABYRINTH:
                cout << "\n\n- " << map[2].get_name() << " -";
                play_forgotten_labyrinth(gameloop, player, state, map);
                break;

            case areas::HALL_OF_EWYL:
                cout << "\n\n- " << map[3].get_name() << " -";
                play_hall_of_ewyl(gameloop, player, state, map);
                break;

            default:
                break;
        }
    }
}
