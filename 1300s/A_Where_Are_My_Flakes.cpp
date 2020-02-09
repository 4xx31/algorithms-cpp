#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/60/A
int main()
{
    int n, m;
    cin >> n >> m;

    int l = 1, r = n;

    string s, t;
    int k;
    while (m--)
    {
        cin >> s >> s >> t >> s >> k;

        if (t == "right")
            l = max(l, k + 1);
        else
            r = min(r, k - 1);
    }

    cout << (r - l + 1 > 0 ? r - l + 1 : -1);
}