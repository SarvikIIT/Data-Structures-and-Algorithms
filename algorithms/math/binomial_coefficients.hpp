/**
 * @file binomial_coefficients.hpp
 * @brief Binomial Coefficients and Related Functions
 * 
 * This header provides implementations of binomial coefficient
 * calculations and related combinatorial functions.
 * 
 * Features:
 * - Binomial coefficient C(n, k)
 * - Pascal's triangle
 * - Multinomial coefficients
 * - Catalan numbers
 * - Stirling numbers
 * - Bell numbers
 * 
 * Time Complexity: O(k) to O(n²) depending on method
 * Space Complexity: O(1) to O(n²) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BINOMIAL_COEFFICIENTS_HPP
#define BINOMIAL_COEFFICIENTS_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class BinomialCoefficients {
private:
    static vector<vector<ll>> pascalTriangle;
    static bool initialized;
    static const int MAX_N = 1000;
    
public:
    /**
     * @brief Initialize Pascal's triangle
     * @param maxN Maximum value for triangle
     * @param mod Modulus
     */
    static void initialize(int maxN = MAX_N, ll mod = MOD) {
        if (initialized) return;
        
        pascalTriangle.assign(maxN + 1, vector<ll>(maxN + 1, 0));
        
        for (int i = 0; i <= maxN; i++) {
            pascalTriangle[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                pascalTriangle[i][j] = ModularArithmetic::add(
                    pascalTriangle[i - 1][j - 1],
                    pascalTriangle[i - 1][j],
                    mod
                );
            }
        }
        
        initialized = true;
    }
    
    /**
     * @brief Calculate binomial coefficient C(n, k)
     * @param n Total items
     * @param k Items to choose
     * @param mod Modulus
     * @return C(n, k) % mod
     */
    static ll binomial(int n, int k, ll mod = MOD) {
        if (k > n || k < 0) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n - k) k = n - k; // Use symmetry
        
        ll result = 1;
        for (int i = 0; i < k; i++) {
            result = ModularArithmetic::multiply(result, n - i, mod);
            result = ModularArithmetic::divide(result, i + 1, mod);
        }
        
        return result;
    }
    
    /**
     * @brief Calculate binomial coefficient using Pascal's triangle
     * @param n Total items
     * @param k Items to choose
     * @param mod Modulus
     * @return C(n, k) % mod
     */
    static ll binomialPascal(int n, int k, ll mod = MOD) {
        if (k > n || k < 0) return 0;
        if (n <= MAX_N) {
            initialize(n, mod);
            return pascalTriangle[n][k];
        }
        return binomial(n, k, mod);
    }
    
    /**
     * @brief Calculate multinomial coefficient
     * @param n Total items
     * @param counts Vector of counts for each type
     * @param mod Modulus
     * @return Multinomial coefficient % mod
     */
    static ll multinomial(int n, const vi& counts, ll mod = MOD) {
        ll result = 1;
        int sum = 0;
        
        for (int count : counts) {
            sum += count;
            if (sum > n) return 0;
        }
        
        if (sum != n) return 0;
        
        for (int count : counts) {
            result = ModularArithmetic::multiply(result, binomial(n, count, mod), mod);
            n -= count;
        }
        
        return result;
    }
    
    /**
     * @brief Generate Pascal's triangle up to n rows
     * @param n Number of rows
     * @param mod Modulus
     * @return 2D vector representing Pascal's triangle
     */
    static vector<vector<ll>> generatePascalTriangle(int n, ll mod = MOD) {
        vector<vector<ll>> triangle(n);
        
        for (int i = 0; i < n; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            
            for (int j = 1; j < i; j++) {
                triangle[i][j] = ModularArithmetic::add(
                    triangle[i - 1][j - 1],
                    triangle[i - 1][j],
                    mod
                );
            }
        }
        
        return triangle;
    }
    
    /**
     * @brief Calculate sum of binomial coefficients C(n, 0) + C(n, 1) + ... + C(n, k)
     * @param n Total items
     * @param k Upper limit
     * @param mod Modulus
     * @return Sum % mod
     */
    static ll sumOfBinomials(int n, int k, ll mod = MOD) {
        ll sum = 0;
        for (int i = 0; i <= k; i++) {
            sum = ModularArithmetic::add(sum, binomial(n, i, mod), mod);
        }
        return sum;
    }
    
    /**
     * @brief Calculate alternating sum of binomial coefficients
     * @param n Total items
     * @param k Upper limit
     * @param mod Modulus
     * @return Alternating sum % mod
     */
    static ll alternatingSum(int n, int k, ll mod = MOD) {
        ll sum = 0;
        for (int i = 0; i <= k; i++) {
            ll term = binomial(n, i, mod);
            if (i % 2 == 1) {
                term = ModularArithmetic::subtract(mod, term, mod);
            }
            sum = ModularArithmetic::add(sum, term, mod);
        }
        return sum;
    }
    
    /**
     * @brief Calculate central binomial coefficient C(2n, n)
     * @param n Number
     * @param mod Modulus
     * @return C(2n, n) % mod
     */
    static ll centralBinomial(int n, ll mod = MOD) {
        return binomial(2 * n, n, mod);
    }
    
    /**
     * @brief Calculate Catalan number using binomial coefficient
     * @param n Index
     * @param mod Modulus
     * @return nth Catalan number % mod
     */
    static ll catalan(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = binomial(2 * n, n, mod);
        result = ModularArithmetic::divide(result, n + 1, mod);
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
     * @brief Calculate Bell number (sum of Stirling numbers)
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
     * @brief Calculate Lah number L(n, k)
     * @param n Total items
     * @param k Number of blocks
     * @param mod Modulus
     * @return L(n, k) % mod
     */
    static ll lah(int n, int k, ll mod = MOD) {
        if (k > n || k < 0) return 0;
        if (k == 0) return (n == 0) ? 1 : 0;
        if (k == 1) return factorial(n, mod);
        if (k == n) return 1;
        
        ll result = binomial(n - 1, k - 1, mod);
        result = ModularArithmetic::multiply(result, factorial(n, mod), mod);
        result = ModularArithmetic::divide(result, factorial(k, mod), mod);
        
        return result;
    }
    
private:
    /**
     * @brief Calculate factorial (helper function)
     * @param n Number
     * @param mod Modulus
     * @return n! % mod
     */
    static ll factorial(int n, ll mod) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = 1;
        for (int i = 2; i <= n; i++) {
            result = ModularArithmetic::multiply(result, i, mod);
        }
        return result;
    }
};

// Static member definitions
vector<vector<ll>> BinomialCoefficients::pascalTriangle;
bool BinomialCoefficients::initialized = false;

#endif // BINOMIAL_COEFFICIENTS_HPP
