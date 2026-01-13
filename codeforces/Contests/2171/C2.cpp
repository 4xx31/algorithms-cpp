//
// DISCLAIMER: This is NOT production-quality code.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        int xorA = 0, xorB = 0;
        for (int i = 0; i < n; ++i)
        {
            xorA ^= a[i];
            xorB ^= b[i];
        }

        int D = xorA ^ xorB;

        if (D == 0)
        {
            cout << "Tie\n";
            continue;
        }

        int k = 0;
        for (int bit = 31; bit >= 0; --bit)
        {
            if (D & (1 << bit))
            {
                k = bit;
                break;
            }
        }

        int last = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            int d = a[i] ^ b[i];
            if (d & (1 << k))
            {
                last = i; // 0-based
                break;
            }
        }

        if (last % 2 == 0)
        {
            cout << "Ajisai\n";
        }
        else
        {
            cout << "Mai\n";
        }
    }

    return 0;
}