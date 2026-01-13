//
// DISCLAIMER: This is NOT production-quality code.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        int m = n / 2;
        cout << (m / 2 + 1) << "\n";
    }

    return 0;
}