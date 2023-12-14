// https://codeforces.com/problemset/problem/546/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    
    int k, n, w;
    cin >> k >> n >> w;

    int cost = k * w * (w + 1) / 2 - n;
    cout << (cost > 0 ? cost : 0);
}