// https://codeforces.com/problemset/problem/233/A
// DISCLAIMER: This is NOT production-quality code.
#include <bits/stdc++.h>
using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 != 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i += 2)
    {
        cout << i + 1 << ' ' << i << ' ';
    }
}