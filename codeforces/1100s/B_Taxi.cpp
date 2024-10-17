// https://codeforces.com/problemset/problem/158/B
#include <iostream>

using namespace std;

int n, t;
int a[5];
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> t;
        a[t]++; // Count occurrence of cardinality of groups
    }

    int ans = a[4];
    ans += a[3] + (a[2] * 2 + max(a[1] - a[3], 0) + 3) / 4;

    cout << ans;
}