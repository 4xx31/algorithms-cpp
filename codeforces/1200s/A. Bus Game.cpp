// https://codeforces.com/problemset/problem/79/A
// DISCLAIMER: This is NOT production-quality code.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    while (1)
    {
        if (x >= 2 && y >= 2)
        {
            x -= 2;
            y -= 2;
        }
        else if (x >= 1 && y >= 12)
        {
            x -= 1;
            y -= 12;
        }
        else if (y >= 22)
            y -= 22;
        else
        {
            cout << "Hanako" << endl;
            break;
        }

        if (y >= 22)
        {
            y -= 22;
        }
        else if (x >= 1 && y >= 12)
        {
            x -= 1;
            y -= 12;
        }
        else if (x >= 2 && y >= 2)
        {
            x -= 2;
            y -= 2;
        }
        else
        {
            cout << "Ciel" << endl;
            break;
        }
    }
    return 0;
}