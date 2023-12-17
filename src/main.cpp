#include <iostream>
#include <cstring>
#include <cmath>

#include "Tic_Tac_Toe_App.h"
#include "main_X_O_4.h"
#include "X_O_Pyramid.h"
using namespace std;

int main()
{

    int gameChoice;
    cout << "welcome to Tic-Tac-Tie game";
    cout << "Tic-Tac-Toe - Pyramid, 6x7, 5x5";
    cout << "The game has 3 options - tic-tac-toe(Pyramid),  4x4 and 5x5";
    cout << "Play tic-tac-toe(Pyramid) press 1: \n";
    cout << "Play tic-tac-toe(6x7) press 2: \n";
    cout << "Play tic-tac-toe(5x5) press 3: \n";

    cout << "Choice: ";
    cin >> gameChoice;

    cout << endl;

    while (true)
    {
        if (gameChoice == 1)
        {
            // Play tic-tac-toe(Pyramid)
            run_xo_Pyramic();
            break;
        }
        else if (gameChoice == 2)
        {
            X_O_4();
            break;
        }
        else if (gameChoice == 3)
        {
            // Play tic-tac-toe(5x5)
            Tic_Tac_Toe_5x5();
            break;
        }
        else
        {
            cout << "PLease Enter a valid choice: ";
            cin >> gameChoice;
        }
    }

    cin.get();
}