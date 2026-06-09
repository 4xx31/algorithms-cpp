// https://www.codingame.com/ide/puzzle/1d-bush-fire
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        int drops = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == 'f')
            {
                drops++;
                i += 2; // Assume we'll always throw water on the spot to the right
            }
        }

        cout << drops << endl;
    }
}