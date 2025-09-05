/**
 * @file fibonacci.cpp
 * @brief Fibonacci Sequence Implementation using Dynamic Programming
 * 
 * This file demonstrates two approaches to solve the Fibonacci sequence problem:
 * 1. Memoization (Top-down approach)
 * 2. Tabulation (Bottom-up approach)
 * 
 * Problem: Find the nth Fibonacci number where F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 * 
 * Time Complexity:
 * - Memoization: O(n) with O(n) space
 * - Tabulation: O(n) with O(n) space
 * - Space optimized: O(n) with O(1) space
 * 
 * @author Sarvik
 * @version 1.0
 */

#include "utilities/common.hpp"
#include "utilities/math_utils.hpp"

class Fibonacci {
private:
    static vi dp;
    
public:
    /**
     * @brief Memoization approach for Fibonacci
     * @param n Position in Fibonacci sequence
     * @return nth Fibonacci number
     */
    static int fibonacciMemo(int n) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
    }
    
    /**
     * @brief Tabulation approach for Fibonacci
     * @param n Position in Fibonacci sequence
     * @return nth Fibonacci number
     */
    static int fibonacciTab(int n) {
        if (n <= 1) return n;
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    /**
     * @brief Space-optimized Fibonacci
     * @param n Position in Fibonacci sequence
     * @return nth Fibonacci number
     */
    static int fibonacciSpaceOptimized(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0, prev1 = 1, curr;
        
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
    
    /**
     * @brief Matrix exponentiation approach for Fibonacci (O(log n))
     * @param n Position in Fibonacci sequence
     * @return nth Fibonacci number
     */
    static int fibonacciMatrix(int n) {
        if (n <= 1) return n;
        
        vvl matrix = {{1, 1}, {1, 0}};
        matrix = matrixPower(matrix, n - 1);
        return matrix[0][0];
    }
    
    /**
     * @brief Initialize DP array
     * @param n Size of DP array
     */
    static void initialize(int n) {
        dp.assign(n + 1, -1);
    }
    
private:
    static vvl matrixMultiply(const vvl& a, const vvl& b) {
        int n = sz(a);
        vvl result(n, vl(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] = add(result[i][j], mul(a[i][k], b[k][j]));
                }
            }
        }
        
        return result;
    }
    
    static vvl matrixPower(vvl matrix, int power) {
        int n = sz(matrix);
        vvl result(n, vl(n, 0));
        
        // Initialize result as identity matrix
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        while (power > 0) {
            if (power & 1) {
                result = matrixMultiply(result, matrix);
            }
            matrix = matrixMultiply(matrix, matrix);
            power >>= 1;
        }
        
        return result;
    }
};

vi Fibonacci::dp;

void solve() {
    int n;
    cin >> n;
    
    // Initialize DP array
    Fibonacci::initialize(n);
    
    // Test all approaches
    cout << "Memoization: " << Fibonacci::fibonacciMemo(n) << endl;
    cout << "Tabulation: " << Fibonacci::fibonacciTab(n) << endl;
    cout << "Space Optimized: " << Fibonacci::fibonacciSpaceOptimized(n) << endl;
    cout << "Matrix Exponentiation: " << Fibonacci::fibonacciMatrix(n) << endl;
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
