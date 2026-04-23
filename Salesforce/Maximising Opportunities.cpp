#include <bits/stdc++.h>
using namespace std;

int getMaximumOpportunitySum(vector<vector<int>> dashboard, int k) {
    int n = dashboard.size();

    // For each row, best[i][t] = max sum taking t elements from row i
    // (from left, right, or split)
    vector<vector<int>> best(n);

    for (int i = 0; i < n; i++) {
        int m = dashboard[i].size();
        // Can take 0..m elements from this row
        best[i].resize(min(m, k) + 1, 0);

        // prefix sums
        vector<int> pre(m+1, 0), suf(m+1, 0);
        for (int j = 0; j < m; j++) pre[j+1] = pre[j] + dashboard[i][j];
        for (int j = m-1; j >= 0; j--) suf[j] = suf[j+1] + dashboard[i][j+1];

        for (int t = 1; t <= min(m, k); t++) {
            int val = 0;
            // Take t from left
            val = max(val, pre[t]);
            // Take t from right
            val = max(val, suf[m - t]);
            // Split: l from left, r from right, l+r = t
            for (int l = 1; l < t; l++) {
                int r = t - l;
                if (r <= m - l)
                    val = max(val, pre[l] + suf[m - r]);
            }
            best[i][t] = val;
        }
    }

    // DP across rows
    vector<long long> dp(k+1, LLONG_MIN);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<long long> ndp(k+1, LLONG_MIN);
        int maxTake = best[i].size() - 1;
        for (int j = 0; j <= k; j++) {
            if (dp[j] == LLONG_MIN) continue;
            // Take 0..maxTake from row i
            for (int t = 0; t <= maxTake && j + t <= k; t++) {
                ndp[j+t] = max(ndp[j+t], dp[j] + best[i][t]);
            }
        }
        dp = ndp;
    }

    return (int)dp[k];
}
