// https://codeforces.com/problemset/problem/282/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    string operation;
    int n, x;
    cin >> n;

    while ( n-- > 0)
    {
        cin >> operation;
        
        // Check if operation is ++X or X++
        if (operation[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }

    cout << x;
}