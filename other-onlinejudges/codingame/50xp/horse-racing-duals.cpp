// https://www.codingame.com/ide/puzzle/horse-racing-duals
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int diff, minDiff = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        diff = a[i] - a[i - 1];
        minDiff = min(diff, minDiff);
    }

    cout << minDiff << endl;
}