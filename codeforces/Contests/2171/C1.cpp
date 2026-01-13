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

        int p = 0;          // parity of (1,1) pairs
        vector<int> owners; // 0 = Ajisai, 1 = Mai

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1 && b[i] == 1)
            {
                // contributes 1 to both XORs, no choice
                p ^= 1;
            }
            else if (a[i] != b[i])
            {
                // {0,1} pair: controlling player decides who gets the 1
                if ((i + 1) % 2 == 1)
                {
                    owners.push_back(0); // Ajisai (odd index)
                }
                else
                {
                    owners.push_back(1); // Mai (even index)
                }
            }
            // (0,0) pairs are completely irrelevant
        }

        // Base DP when no tokens remain: just compare final bits.
        int dpNext[2][2];
        for (int A = 0; A < 2; ++A)
        {
            for (int B = 0; B < 2; ++B)
            {
                if (A > B)
                    dpNext[A][B] = 1;
                else if (A < B)
                    dpNext[A][B] = -1;
                else
                    dpNext[A][B] = 0;
            }
        }

        // Process tokens from last to first
        for (int idx = (int)owners.size() - 1; idx >= 0; --idx)
        {
            int dpCurr[2][2];
            if (owners[idx] == 0)
            {
                // Ajisai's turn: maximize result
                for (int A = 0; A < 2; ++A)
                {
                    for (int B = 0; B < 2; ++B)
                    {
                        int v1 = dpNext[A ^ 1][B]; // toggle A
                        int v2 = dpNext[A][B ^ 1]; // toggle B
                        dpCurr[A][B] = max(v1, v2);
                    }
                }
            }
            else
            {
                // Mai's turn: minimize Ajisai's result
                for (int A = 0; A < 2; ++A)
                {
                    for (int B = 0; B < 2; ++B)
                    {
                        int v1 = dpNext[A ^ 1][B]; // toggle A
                        int v2 = dpNext[A][B ^ 1]; // toggle B
                        dpCurr[A][B] = min(v1, v2);
                    }
                }
            }
            // Copy dpCurr into dpNext
            for (int A = 0; A < 2; ++A)
                for (int B = 0; B < 2; ++B)
                    dpNext[A][B] = dpCurr[A][B];
        }

        int result = dpNext[p][p]; // starting from (A,B) = (p,p)

        if (result > 0)
        {
            cout << "Ajisai\n";
        }
        else if (result < 0)
        {
            cout << "Mai\n";
        }
        else
        {
            cout << "Tie\n";
        }
    }

    return 0;
}