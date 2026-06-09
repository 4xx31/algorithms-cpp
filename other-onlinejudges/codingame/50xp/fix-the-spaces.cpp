// https://www.codingame.com/ide/puzzle/fix-the-spaces
#include <bits/stdc++.h>
using namespace std;

void findValidSplits(string sentence, map<string, int>& wordFreq, vector<string>& currentSplit, vector<vector<string>>& allSplits)
{
    // Base case: empty sentence -> store current split
    if (sentence.empty())
    {
        allSplits.push_back(currentSplit);
        return;
    }

    // Iterate over all possible prefixes
    for (int i = 0; i < sentence.length(); i++)
    {
        string prefix = sentence.substr(0, i + 1);
        if (wordFreq.count(prefix) > 0 && wordFreq[prefix] > 0)
        {
            // Choose the word (decrement count)
            --wordFreq[prefix];
            currentSplit.push_back(prefix);

            // Recur for the remaining substring
            findValidSplits(sentence.substr(i + 1), wordFreq, currentSplit, allSplits);

            // Backtrack (restore count and split)
            currentSplit.pop_back();
            ++wordFreq[prefix];
        }
    }
}

int main()
{
    string original;
    getline(cin, original);
    string words;
    getline(cin, words);

    map<string, int> wordFreq; // Build dictionary of occurrences
    stringstream ss(words);
    string word;
    while (ss >> word)
        ++wordFreq[word];

    vector<vector<string>> allSplits;
    vector<string> currentSplit;
    findValidSplits(original, wordFreq, currentSplit, allSplits);

    if (allSplits.size() == 1) // Only one solution
    {
        for (int i = 0; i < allSplits[0].size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << allSplits[0][i];
        }
        cout << endl;
    }
    else
        cout << "Unsolvable" << endl;
}
