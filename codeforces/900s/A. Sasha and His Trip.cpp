// https://codeforces.com/problemset/problem/1113/A
// DISCLAIMER: This is NOT production-quality code.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

    // Pre-load tank (v) for last cities
    int result = min(n - 1, v);

    // Keep tank at max in first (cheaper) cities
    for (int i = 2; i <= n - v; i++)
    {
        result += i;
    }

    cout << result;
}