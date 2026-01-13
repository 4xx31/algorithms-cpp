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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<long long> ans = a;

        // Fix endpoints to minimize |a_n - a_1|
        if (ans[0] == -1 && ans[n - 1] == -1)
        {
            // Both free: choose 0, 0 for lexicographically smallest and value 0
            ans[0] = ans[n - 1] = 0;
        }
        else if (ans[0] == -1)
        {
            // Only first is free: match last to get difference 0
            ans[0] = ans[n - 1];
        }
        else if (ans[n - 1] == -1)
        {
            // Only last is free: match first to get difference 0
            ans[n - 1] = ans[0];
        }
        // If both known, we leave them as is.

        long long best = llabs(ans[n - 1] - ans[0]);

        // Fill middle -1's with 0 for lexicographically smallest array
        for (int i = 1; i < n - 1; ++i)
        {
            if (ans[i] == -1)
            {
                ans[i] = 0;
            }
        }

        cout << best << "\n";
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}