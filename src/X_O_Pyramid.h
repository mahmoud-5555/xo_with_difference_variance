// Class definition the main function that start xo_pyeamid game play
// Author:  mahmoud Ahmed
// Date:    12/16/2023
// Version: 1

#include <iostream>

#include "BoardGame_Classes.hpp"
using namespace std;

void run_xo_Pyramic()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Pyramic Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 5);

    GameManager x_o_game(new xo_Pyramic, players);
    x_o_game.run();
}
