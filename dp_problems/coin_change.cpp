/**
 * @file coin_change.cpp
 * @brief Coin Change Problem Implementation
 * 
 * This file demonstrates multiple approaches to solve the coin change problem:
 * 1. Memoization (Top-down approach)
 * 2. Tabulation (Bottom-up approach)
 * 3. Space-optimized tabulation
 * 4. Count of ways to make change
 * 5. Minimum coins with actual solution reconstruction
 * 
 * Problem: Given coins of different denominations and a total amount,
 * find the minimum number of coins needed to make up that amount.
 * 
 * Time Complexity:
 * - Memoization: O(amount * coins)
 * - Tabulation: O(amount * coins)
 * - Space Optimized: O(amount * coins) with O(amount) space
 * 
 * @author Competitive Programming Library
 * @version 1.0
 */

#include "utilities/common.h"
#include "utilities/math_utils.h"

class CoinChange {
private:
    static vi coins;
    static vi dp;
    static const int INF = 1e9;
    
public:
    /**
     * @brief Memoization approach for minimum coins
     * @param amount Target amount
     * @return Minimum number of coins needed, or -1 if impossible
     */
    static int minCoinsMemo(int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INF;
        if (dp[amount] != -1) return dp[amount];
        
        int result = INF;
        for (int coin : coins) {
            if (amount >= coin) {
                result = min(result, 1 + minCoinsMemo(amount - coin));
            }
        }
        
        return dp[amount] = result;
    }
    
    /**
     * @brief Tabulation approach for minimum coins
     * @param amount Target amount
     * @param coinValues Available coin denominations
     * @return Minimum number of coins needed, or -1 if impossible
     */
    static int minCoinsTab(int amount, const vi& coinValues) {
        vi dp(amount + 1, INF);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coinValues) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        return dp[amount] == INF ? -1 : dp[amount];
    }
    
    /**
     * @brief Count number of ways to make change
     * @param amount Target amount
     * @param coinValues Available coin denominations
     * @return Number of ways to make change
     */
    static int countWays(int amount, const vi& coinValues) {
        vi dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coinValues) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
    
    /**
     * @brief Get actual solution (coins used)
     * @param amount Target amount
     * @param coinValues Available coin denominations
     * @return Vector of coins used in the solution
     */
    static vi getSolution(int amount, const vi& coinValues) {
        vi dp(amount + 1, INF);
        vi parent(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coinValues) {
                if (i >= coin && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    parent[i] = coin;
                }
            }
        }
        
        if (dp[amount] == INF) return {};
        
        vi result;
        int current = amount;
        while (current > 0) {
            result.pb(parent[current]);
            current -= parent[current];
        }
        
        return result;
    }
    
    /**
     * @brief Space-optimized solution for minimum coins
     * @param amount Target amount
     * @param coinValues Available coin denominations
     * @return Minimum number of coins needed
     */
    static int minCoinsSpaceOptimized(int amount, const vi& coinValues) {
        vi dp(amount + 1, INF);
        dp[0] = 0;
        
        for (int coin : coinValues) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        
        return dp[amount] == INF ? -1 : dp[amount];
    }
    
    /**
     * @brief Initialize DP array and coins
     * @param coinValues Available coin denominations
     * @param amount Target amount
     */
    static void initialize(const vi& coinValues, int amount) {
        coins = coinValues;
        dp.assign(amount + 1, -1);
    }
    
    /**
     * @brief Solve coin change using all approaches
     * @param amount Target amount
     * @param coinValues Available coin denominations
     */
    static void solveAll(int amount, const vi& coinValues) {
        initialize(coinValues, amount);
        
        cout << "Target amount: " << amount << endl;
        cout << "Available coins: ";
        for (int coin : coinValues) cout << coin << " ";
        cout << endl;
        
        // Memoization
        int memoResult = minCoinsMemo(amount);
        cout << "Memoization result: " << (memoResult == INF ? -1 : memoResult) << endl;
        
        // Tabulation
        cout << "Tabulation result: " << minCoinsTab(amount, coinValues) << endl;
        
        // Space optimized
        cout << "Space optimized result: " << minCoinsSpaceOptimized(amount, coinValues) << endl;
        
        // Count ways
        cout << "Number of ways: " << countWays(amount, coinValues) << endl;
        
        // Get solution
        vi solution = getSolution(amount, coinValues);
        if (!solution.empty()) {
            cout << "Solution coins: ";
            for (int coin : solution) cout << coin << " ";
            cout << endl;
        } else {
            cout << "No solution exists" << endl;
        }
    }
};

vi CoinChange::coins;
vi CoinChange::dp;

void solve() {
    int n, amount;
    cin >> n >> amount;
    
    vi coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    CoinChange::solveAll(amount, coins);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
