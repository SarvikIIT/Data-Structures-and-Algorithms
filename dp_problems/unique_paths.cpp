/**
 * @file unique_paths.cpp
 * @brief Unique Paths Problem (2D DP)
 * 
 * This file contains implementations for counting the number of
 * unique paths from top-left to bottom-right in a grid.
 * 
 * Problem: Count unique paths in m x n grid
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 * 
 * @author Sarvik
 * @version 1.0
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base cases: first row and first column have only 1 path
        for(int i = 0; i < m; ++i) dp[i][0] = 1;
        for(int i = 0; i < n; ++i) dp[0][i] = 1;

        // Fill DP table
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
