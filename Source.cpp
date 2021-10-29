/** **************************** **/
/** https://github.com/amir0026a **/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int bomb_count, checkx, checky;
const int sizex = 10, sizey = 10;


bool lose;

class Grid {
public:
    bool has_bomb, marked;
    Grid(void) {
        has_bomb = false;
        marked = false;
    }
};

void drawBoad(Grid board[sizex][sizey])
{
    //  _0_1_2_3_4_5_6_7_8_9_
    // 0|_|_|_|_|_|_|_|_|_|_|
    // 1|_|_|_|_|_|_|_|_|_|_|
    // 2|_|_|_|_|_|_|_|_|_|_|
    // 3|_|_|_|_|_|_|_|_|_|_|
    // 4|_|_|_|_|_|_|_|_|_|_|
    // 5|_|_|_|_|_|_|_|_|_|_|
    // 6|_|_|_|_|_|_|_|_|_|_|
    // 7|_|_|_|_|_|_|_|_|_|_|
    // 8|_|_|_|_|_|_|_|_|_|_|
    // 9|_|_|_|_|_|_|_|_|_|_|

    //This draws the top line
    cout << " _";
    for (int i = 0; i < sizex; i++)
    {
        cout << i << "_";
    }
    cout << endl;

    //This draws the body
    for (int y = 0; y < sizey; y++)
    {
        cout << y << "|";
        for (int x = 0; x < sizex; x++)
        {
            if (board[x][y].has_bomb && board[x][y].marked)
            {
                cout << "!|";
            }
            if (board[x][y].has_bomb)
            {
                cout << "b|";
            }
            else if (board[x][y].marked)
            {
                cout << "x|";
            }
            else
            {
                cout << "_|";
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "This File Is Downloaded From :\nhttps://github.com/amir0026a/minsweeper\n";
    lose = false;
    bomb_count = 15;
    checkx = 0;
    checky = 0;
    Grid gameboard[sizex][sizey];
    for (int i = 0; i < bomb_count; i++)
    {
        int xpos = rand() % 10;
        int ypos = rand() % 10;
        if (gameboard[xpos][ypos].has_bomb == false) {
            gameboard[xpos][ypos].has_bomb = true;
        }
        else
        {
            i--;
        }
    }
    drawBoad(gameboard);
    cout << endl;
    while (lose != true)
    {
        cout << "Input x grid to check." << endl;
        cin >> checkx;
        cout << endl << "Input y grid to check." << endl;
        cin >> checky;
        if (gameboard[checkx - 1][checky - 1].has_bomb == true) {
            cout << "Boom!";
            lose = true;
        }
        else {
            cout << "Try again." << endl;
        }
        gameboard[checkx - 1][checky - 1].marked = true;

        cout << endl;
        drawBoad(gameboard);
        cout << endl;
    }

    return 0;
}