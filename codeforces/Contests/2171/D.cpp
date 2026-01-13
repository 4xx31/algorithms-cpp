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
        vector<int> p(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }

        // pos[x] = position (1-based) of label x in permutation p
        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i)
        {
            pos[p[i]] = i + 1;
        }

        // pref_min[k] = minimum position among labels 1..k
        const int INF = (int)1e9;
        vector<int> pref_min(n + 1), suff_max(n + 2);

        int cur = INF;
        for (int k = 1; k <= n; ++k)
        {
            cur = min(cur, pos[k]);
            pref_min[k] = cur;
        }

        // suff_max[k] = maximum position among labels k..n
        cur = -1;
        for (int k = n; k >= 1; --k)
        {
            cur = max(cur, pos[k]);
            suff_max[k] = cur;
        }

        bool ok = true;
        for (int k = 1; k <= n - 1; ++k)
        {
            if (pref_min[k] > suff_max[k + 1])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}