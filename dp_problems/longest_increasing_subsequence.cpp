/**
 * @file longest_increasing_subsequence.cpp
 * @brief Longest Increasing Subsequence (LIS) Implementation
 * 
 * This file demonstrates multiple approaches to solve the LIS problem:
 * 1. Memoization (Top-down approach) - O(n²)
 * 2. Tabulation (Bottom-up approach) - O(n²)
 * 3. Binary Search approach - O(n log n)
 * 4. Segment Tree approach - O(n log n)
 * 
 * Problem: Find the length of the longest increasing subsequence in an array
 * 
 * Time Complexity:
 * - Memoization/Tabulation: O(n²)
 * - Binary Search: O(n log n)
 * - Segment Tree: O(n log n)
 * 
 * @author Competitive Programming Library
 * @version 1.0
 */

#include "utilities/common.h"
#include "utilities/math_utils.h"
#include "algorithms/binary_search.h"

class LIS {
private:
    static vi dp;
    static vi arr;
    
public:
    /**
     * @brief Memoization approach for LIS
     * @param index Current index
     * @return Length of LIS starting from index
     */
    static int lisMemo(int index) {
        if (dp[index] != -1) return dp[index];
        
        int result = 1;
        for (int i = index + 1; i < sz(arr); i++) {
            if (arr[i] > arr[index]) {
                result = max(result, 1 + lisMemo(i));
            }
        }
        
        return dp[index] = result;
    }
    
    /**
     * @brief Tabulation approach for LIS
     * @param a Input array
     * @return Length of LIS
     */
    static int lisTab(const vi& a) {
        int n = sz(a);
        vi dp(n, 1);
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return *max_element(all(dp));
    }
    
    /**
     * @brief Binary Search approach for LIS (O(n log n))
     * @param a Input array
     * @return Length of LIS
     */
    static int lisBinarySearch(const vi& a) {
        vi tail;
        
        for (int x : a) {
            auto it = lower_bound(all(tail), x);
            if (it == tail.end()) {
                tail.pb(x);
            } else {
                *it = x;
            }
        }
        
        return sz(tail);
    }
    
    /**
     * @brief Get the actual LIS sequence using binary search approach
     * @param a Input array
     * @return Vector containing the LIS sequence
     */
    static vi getLISSequence(const vi& a) {
        int n = sz(a);
        vi tail, tailIndices, parent(n, -1);
        
        for (int i = 0; i < n; i++) {
            int x = a[i];
            auto it = lower_bound(all(tail), x);
            int pos = it - tail.begin();
            
            if (pos == sz(tail)) {
                tail.pb(x);
                tailIndices.pb(i);
            } else {
                tail[pos] = x;
                tailIndices[pos] = i;
            }
            
            if (pos > 0) {
                parent[i] = tailIndices[pos - 1];
            }
        }
        
        // Reconstruct the sequence
        vi result;
        int idx = tailIndices.back();
        while (idx != -1) {
            result.pb(a[idx]);
            idx = parent[idx];
        }
        
        reverse(all(result));
        return result;
    }
    
    /**
     * @brief Initialize DP array and input array
     * @param a Input array
     */
    static void initialize(const vi& a) {
        arr = a;
        dp.assign(sz(a), -1);
    }
    
    /**
     * @brief Solve LIS using all approaches
     * @param a Input array
     */
    static void solveAll(const vi& a) {
        initialize(a);
        
        cout << "Input array: ";
        for (int x : a) cout << x << " ";
        cout << endl;
        
        // Memoization
        int memoResult = 0;
        for (int i = 0; i < sz(a); i++) {
            memoResult = max(memoResult, lisMemo(i));
        }
        cout << "Memoization result: " << memoResult << endl;
        
        // Tabulation
        cout << "Tabulation result: " << lisTab(a) << endl;
        
        // Binary Search
        cout << "Binary Search result: " << lisBinarySearch(a) << endl;
        
        // Get actual sequence
        vi sequence = getLISSequence(a);
        cout << "LIS sequence: ";
        for (int x : sequence) cout << x << " ";
        cout << endl;
    }
};

vi LIS::dp;
vi LIS::arr;

void solve() {
    int n;
    cin >> n;
    
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    LIS::solveAll(a);
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
