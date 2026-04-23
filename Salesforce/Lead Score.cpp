#include <bits/stdc++.h>
using namespace std;

long optimizeLeadScores(vector<int> leadScores) {
    int n = leadScores.size();
    // Find length of longest non-decreasing subsequence
    // Elements not in it each need 1 operation
    vector<int> dp; // tails of non-decreasing subsequences

    for (int x : leadScores) {
        // upper_bound for non-decreasing (allow equal)
        auto it = upper_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    return (long)(n - (int)dp.size());
}
