// https://www.codingame.com/ide/puzzle/shoot-enemy-aircraft
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        std::cin >> grid[i];

    // Last line (get launcherPos)
    int launcherPos = 0;
    for (int j = 0; j < grid[n - 1].length(); j++)
    {
        if (grid[n - 1][j] == '^')
        {
            launcherPos = j;
            break;
        }
    }

    // Other lines
    unordered_set<int> shootTimes;
    for (int col = 0; col < n - 1; col++)
    {
        for (int row = 0; row < grid[0].length(); row++)
        {
            if (grid[col][row] != '<' && grid[col][row] != '>')
                continue;

            shootTimes.insert(abs(launcherPos - row) - (n - col));
        }
    }

    const int lastShootTime = *std::max_element(shootTimes.begin(), shootTimes.end());
    for (int time = 0; time <= lastShootTime; time++)
    {
        cout << (shootTimes.contains(time) ? "SHOOT" : "WAIT") << endl;
    }
}