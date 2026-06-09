// https://www.codingame.com/ide/puzzle/power-of-thor
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int light_x;    // the X position of the light of power
    int light_y;    // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty;
    cin.ignore();

    int diffX = initial_tx - light_x;
    int diffY = initial_ty - light_y;

    // game loop
    while (1)
    {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns;
        cin.ignore();

        if (diffX == 0 && diffY == 0)
        {
            break;
        }

        string direction = "";
        if (diffY > 0)
        {
            direction = "N";
            diffY--;
        }
        else if (diffY < 0)
        {
            direction = "S";
            diffY++;
        }

        if (diffX < 0)
        {
            direction += "E";
            diffX++;
        }
        else if (diffX > 0)
        {
            direction += "W";
            diffX--;
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << direction << endl;
    }
}