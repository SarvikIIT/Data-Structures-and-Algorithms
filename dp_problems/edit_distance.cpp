/**
 * @file edit_distance.cpp
 * @brief Edit Distance (Levenshtein Distance) Problem
 * 
 * This file contains implementations for calculating the minimum
 * number of operations (insert, delete, replace) required to
 * transform one string into another.
 * 
 * Problem: Given two strings, find the minimum edit distance
 * Time Complexity: O(m * n) where m, n are string lengths
 * Space Complexity: O(m * n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 5001;
string a, b;
int dp[N][N];

void solve() {
    cin >> a >> b;
    int n = a.size(), m = b.size();

    // Base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({ dp[i - 1][j],      // Delete
                                     dp[i][j - 1],      // Insert
                                     dp[i - 1][j - 1]   // Replace
                                   });
        }
    }

    cout << dp[n][m] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
