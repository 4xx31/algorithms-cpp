// https://www.codingame.com/ide/puzzle/1000000000d-world
#include <bits/stdc++.h>
using namespace std;

vector<int> getvector(const string& str)
{
    istringstream iss(str);
    return vector<int>((istream_iterator<int>(iss)), istream_iterator<int>());
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    auto v1{ getvector(a) }, v2{ getvector(b) };
    long long ans = 0, n = 0, m = 0, times;

    while (n < size(v1))
    {
        times = min(v1[n], v2[m]);
        v1[n] -= times;
        v2[m] -= times;
        ans += times * v1[n + 1] * v2[m + 1];

        if (v1[n] == 0)
            n += 2;
        if (v2[m] == 0)
            m += 2;
    }

    cout << ans << endl;
}