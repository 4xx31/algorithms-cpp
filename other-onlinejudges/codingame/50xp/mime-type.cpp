// https://www.codingame.com/training/easy/mime-type
#include <bits/stdc++.h>
using namespace std;

static inline void ToLowerInPlace(string& s)
{
    for (char& c : s)
    {
        c = (char)tolower((unsigned char)c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    unordered_map<string, string> mime_map;
    mime_map.reserve((size_t)n * 2);
    mime_map.max_load_factor(0.7f);

    string ext, mt;

    while (n--)
    {
        cin >> ext >> mt;
        ToLowerInPlace(ext);
        mime_map[ext] = mt;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // consume endline

    string fname;
    string out;
    out.reserve((size_t)q * 16); // rough guess

    while (q--)
    {
        getline(cin, fname);

        size_t dot_pos = fname.find_last_of('.');

        // Must have a dot, and it must not be the last character.
        if (dot_pos != string::npos && dot_pos + 1 < fname.size())
        {
            string file_ext = fname.substr(dot_pos + 1);
            ToLowerInPlace(file_ext);

            auto it = mime_map.find(file_ext);
            if (it != mime_map.end())
            {
                out += it->second;
                out += '\n';
                continue;
            }
        }

        out += "UNKNOWN\n";
    }

    cout << out;
    return 0;
}
