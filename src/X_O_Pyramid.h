// Class definition the main function that start xo_pyeamid game play
// Author:  mahmoud Ahmed
// Date:    12/16/2023
// Version: 1

#include <iostream>

#include "BoardGame_Classes.hpp"
using namespace std;
/**
 * run_xo_Pyramic - the start point of the game <Pyramic>
 * Return no return value
*/
void run_xo_Pyramic()
{
    // check the choice as char Just in case crashing the program
    char choice;
    Player *players[2];// array of pointer to palyer <opjects from players calss>
    players[0] = new Player(1, 'x');
    //massige for the user
    cout << "Welcome to FCAI X-O Pyramic Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;// take input <char>
    if (choice != '1')
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 5);
    xo_Pyramic *the_board = new xo_Pyramic;

    GameManager x_o_game(the_board, players);
    x_o_game.run();// run the game functon //
    system("pause");
    //free the heap
    delete players[1];
    delete players[0];
    delete the_board;

}
