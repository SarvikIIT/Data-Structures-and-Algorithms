/**
 * @file combinatorics.hpp
 * @brief Combinatorics and Permutation Algorithms
 * 
 * This header provides implementations of combinatorics algorithms
 * including permutations, combinations, and related counting problems.
 * 
 * Features:
 * - Factorial calculation
 * - Permutations and combinations
 * - Multinomial coefficients
 * - Stirling numbers
 * - Catalan numbers
 * - Fibonacci numbers
 * - Binomial coefficients
 * 
 * Time Complexity: O(n) to O(n²) depending on operation
 * Space Complexity: O(n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class Combinatorics {
private:
    static vector<ll> fact;
    static vector<ll> invFact;
    static bool initialized;
    static const int MAX_N = 1000000;
    
public:
    /**
     * @brief Initialize factorial and inverse factorial arrays
     * @param maxN Maximum value for precomputation
     * @param mod Modulus
     */
    static void initialize(int maxN = MAX_N, ll mod = MOD) {
        if (initialized) return;
        
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);
        
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = ModularArithmetic::multiply(fact[i - 1], i, mod);
        }
        
        invFact[maxN] = ModularArithmetic::modInverse(fact[maxN], mod);
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = ModularArithmetic::multiply(invFact[i + 1], i + 1, mod);
        }
        
        initialized = true;
    }
    
    /**
     * @brief Calculate factorial
     * @param n Number
     * @param mod Modulus
     * @return n! % mod
     */
    static ll factorial(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n < sz(fact)) return fact[n];
        
        ll result = 1;
        for (int i = 2; i <= n; i++) {
            result = ModularArithmetic::multiply(result, i, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate combination C(n, r)
     * @param n Total items
     * @param r Items to choose
     * @param mod Modulus
     * @return C(n, r) % mod
     */
    static ll combination(int n, int r, ll mod = MOD) {
        if (r > n || r < 0) return 0;
        if (r == 0 || r == n) return 1;
        
        initialize(n, mod);
        return ModularArithmetic::multiply(
            ModularArithmetic::multiply(fact[n], invFact[r], mod),
            invFact[n - r], mod
        );
    }
    
    /**
     * @brief Calculate permutation P(n, r)
     * @param n Total items
     * @param r Items to arrange
     * @param mod Modulus
     * @return P(n, r) % mod
     */
    static ll permutation(int n, int r, ll mod = MOD) {
        if (r > n || r < 0) return 0;
        if (r == 0) return 1;
        
        initialize(n, mod);
        return ModularArithmetic::multiply(fact[n], invFact[n - r], mod);
    }
    
    /**
     * @brief Calculate multinomial coefficient
     * @param n Total items
     * @param counts Vector of counts for each type
     * @param mod Modulus
     * @return Multinomial coefficient % mod
     */
    static ll multinomial(int n, const vi& counts, ll mod = MOD) {
        ll result = factorial(n, mod);
        for (int count : counts) {
            result = ModularArithmetic::divide(result, factorial(count, mod), mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate Stirling number of the second kind S(n, k)
     * @param n Number of objects
     * @param k Number of non-empty subsets
     * @param mod Modulus
     * @return S(n, k) % mod
     */
    static ll stirlingSecond(int n, int k, ll mod = MOD) {
        if (k > n || k < 0) return 0;
        if (k == 0) return (n == 0) ? 1 : 0;
        if (k == 1 || k == n) return 1;
        
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                dp[i][j] = ModularArithmetic::add(
                    ModularArithmetic::multiply(j, dp[i - 1][j], mod),
                    dp[i - 1][j - 1], mod
                );
            }
        }
        
        return dp[n][k];
    }
    
    /**
     * @brief Calculate Catalan number
     * @param n Index
     * @param mod Modulus
     * @return nth Catalan number % mod
     */
    static ll catalan(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = combination(2 * n, n, mod);
        result = ModularArithmetic::divide(result, n + 1, mod);
        return result;
    }
    
    /**
     * @brief Calculate Fibonacci number
     * @param n Index
     * @param mod Modulus
     * @return nth Fibonacci number % mod
     */
    static ll fibonacci(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return n;
        
        vector<vector<ll>> base = {{1, 1}, {1, 0}};
        vector<vector<ll>> result = matrixPower(base, n - 1, mod);
        return result[0][0];
    }
    
    /**
     * @brief Calculate Bell number (number of partitions of a set)
     * @param n Number of elements
     * @param mod Modulus
     * @return nth Bell number % mod
     */
    static ll bell(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = 0;
        for (int k = 0; k <= n; k++) {
            result = ModularArithmetic::add(result, stirlingSecond(n, k, mod), mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate derangement number !n
     * @param n Number of elements
     * @param mod Modulus
     * @return !n % mod
     */
    static ll derangement(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1 - n;
        
        ll a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            ll temp = ModularArithmetic::multiply(i - 1, ModularArithmetic::add(a, b, mod), mod);
            a = b;
            b = temp;
        }
        return b;
    }
    
private:
    /**
     * @brief Matrix exponentiation for Fibonacci calculation
     * @param matrix Base matrix
     * @param power Exponent
     * @param mod Modulus
     * @return Matrix^power % mod
     */
    static vector<vector<ll>> matrixPower(const vector<vector<ll>>& matrix, int power, ll mod) {
        int n = sz(matrix);
        vector<vector<ll>> result(n, vector<ll>(n, 0));
        
        // Initialize result as identity matrix
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        vector<vector<ll>> base = matrix;
        while (power > 0) {
            if (power & 1) {
                result = matrixMultiply(result, base, mod);
            }
            base = matrixMultiply(base, base, mod);
            power >>= 1;
        }
        
        return result;
    }
    
    /**
     * @brief Matrix multiplication
     * @param a First matrix
     * @param b Second matrix
     * @param mod Modulus
     * @return a * b % mod
     */
    static vector<vector<ll>> matrixMultiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b, ll mod) {
        int n = sz(a);
        vector<vector<ll>> result(n, vector<ll>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] = ModularArithmetic::add(
                        result[i][j],
                        ModularArithmetic::multiply(a[i][k], b[k][j], mod),
                        mod
                    );
                }
            }
        }
        
        return result;
    }
};

// Static member definitions
vector<ll> Combinatorics::fact;
vector<ll> Combinatorics::invFact;
bool Combinatorics::initialized = false;

#endif // COMBINATORICS_HPP
