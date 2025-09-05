/**
 * @file fibonacci.hpp
 * @brief Fibonacci Number Algorithms
 * 
 * This header provides multiple implementations of Fibonacci number
 * calculations with different optimizations.
 * 
 * Features:
 * - Recursive Fibonacci
 * - Iterative Fibonacci
 * - Matrix exponentiation Fibonacci
 * - Fibonacci with memoization
 * - Fibonacci modulo operations
 * - Fibonacci sequence generation
 * 
 * Time Complexity: O(n) to O(log n) depending on method
 * Space Complexity: O(1) to O(n) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class Fibonacci {
private:
    static map<int, ll> memo;
    
public:
    /**
     * @brief Recursive Fibonacci (inefficient)
     * @param n Index
     * @return nth Fibonacci number
     */
    static ll recursive(int n) {
        if (n <= 1) return n;
        return recursive(n - 1) + recursive(n - 2);
    }
    
    /**
     * @brief Iterative Fibonacci
     * @param n Index
     * @return nth Fibonacci number
     */
    static ll iterative(int n) {
        if (n <= 1) return n;
        
        ll a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            ll temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
    
    /**
     * @brief Fibonacci with memoization
     * @param n Index
     * @return nth Fibonacci number
     */
    static ll memoized(int n) {
        if (n <= 1) return n;
        if (memo.find(n) != memo.end()) return memo[n];
        
        memo[n] = memoized(n - 1) + memoized(n - 2);
        return memo[n];
    }
    
    /**
     * @brief Fibonacci using matrix exponentiation (O(log n))
     * @param n Index
     * @return nth Fibonacci number
     */
    static ll matrixExponentiation(int n) {
        if (n <= 1) return n;
        
        vector<vector<ll>> base = {{1, 1}, {1, 0}};
        vector<vector<ll>> result = matrixPower(base, n - 1);
        return result[0][0];
    }
    
    /**
     * @brief Fibonacci modulo m
     * @param n Index
     * @param m Modulus
     * @return nth Fibonacci number % m
     */
    static ll fibonacciMod(int n, ll m) {
        if (n <= 1) return n % m;
        
        ll a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            ll temp = (a + b) % m;
            a = b;
            b = temp;
        }
        return b;
    }
    
    /**
     * @brief Generate Fibonacci sequence up to n terms
     * @param n Number of terms
     * @return Vector of first n Fibonacci numbers
     */
    static vi generateSequence(int n) {
        vi sequence;
        if (n <= 0) return sequence;
        
        sequence.pb(0);
        if (n == 1) return sequence;
        
        sequence.pb(1);
        for (int i = 2; i < n; i++) {
            sequence.pb(sequence[i - 1] + sequence[i - 2]);
        }
        
        return sequence;
    }
    
    /**
     * @brief Check if a number is Fibonacci
     * @param num Number to check
     * @return true if num is a Fibonacci number
     */
    static bool isFibonacci(ll num) {
        if (num < 0) return false;
        if (num <= 1) return true;
        
        ll a = 0, b = 1;
        while (b < num) {
            ll temp = a + b;
            a = b;
            b = temp;
        }
        
        return b == num;
    }
    
    /**
     * @brief Find index of Fibonacci number
     * @param num Fibonacci number
     * @return Index of the number, -1 if not found
     */
    static int findIndex(ll num) {
        if (num < 0) return -1;
        if (num <= 1) return num;
        
        ll a = 0, b = 1;
        int index = 1;
        
        while (b < num) {
            ll temp = a + b;
            a = b;
            b = temp;
            index++;
        }
        
        return (b == num) ? index : -1;
    }
    
    /**
     * @brief Calculate sum of Fibonacci numbers up to n
     * @param n Upper limit
     * @return Sum of F(0) + F(1) + ... + F(n)
     */
    static ll sumUpTo(int n) {
        if (n < 0) return 0;
        if (n <= 1) return n;
        
        ll a = 0, b = 1, sum = 1;
        for (int i = 2; i <= n; i++) {
            ll temp = a + b;
            a = b;
            b = temp;
            sum += b;
        }
        return sum;
    }
    
    /**
     * @brief Find nth Fibonacci number using Binet's formula
     * @param n Index
     * @return nth Fibonacci number (approximate for large n)
     */
    static double binetFormula(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        
        return (pow(phi, n) - pow(psi, n)) / sqrt5;
    }
    
    /**
     * @brief Calculate Pisano period for modulo m
     * @param m Modulus
     * @return Length of Pisano period
     */
    static int pisanoPeriod(int m) {
        if (m <= 1) return 1;
        
        int a = 0, b = 1, period = 0;
        do {
            int temp = (a + b) % m;
            a = b;
            b = temp;
            period++;
        } while (a != 0 || b != 1);
        
        return period;
    }
    
private:
    /**
     * @brief Matrix power for Fibonacci calculation
     * @param matrix Base matrix
     * @param power Exponent
     * @return Matrix^power
     */
    static vector<vector<ll>> matrixPower(const vector<vector<ll>>& matrix, int power) {
        int n = sz(matrix);
        vector<vector<ll>> result(n, vector<ll>(n, 0));
        
        // Initialize result as identity matrix
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        vector<vector<ll>> base = matrix;
        while (power > 0) {
            if (power & 1) {
                result = matrixMultiply(result, base);
            }
            base = matrixMultiply(base, base);
            power >>= 1;
        }
        
        return result;
    }
    
    /**
     * @brief Matrix multiplication
     * @param a First matrix
     * @param b Second matrix
     * @return a * b
     */
    static vector<vector<ll>> matrixMultiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
        int n = sz(a);
        vector<vector<ll>> result(n, vector<ll>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        return result;
    }
};

// Static member definition
map<int, ll> Fibonacci::memo;

#endif // FIBONACCI_HPP
