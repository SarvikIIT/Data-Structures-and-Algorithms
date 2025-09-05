/**
 * @file factorial.hpp
 * @brief Factorial and Related Functions
 * 
 * This header provides implementations of factorial calculations
 * and related mathematical functions.
 * 
 * Features:
 * - Factorial calculation
 * - Double factorial
 * - Rising and falling factorials
 * - Factorial modulo operations
 * - Stirling numbers
 * - Wilson's theorem
 * 
 * Time Complexity: O(n) for basic factorial
 * Space Complexity: O(1) to O(n) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class Factorial {
private:
    static vector<ll> factCache;
    static bool initialized;
    static const int MAX_CACHE = 1000000;
    
public:
    /**
     * @brief Initialize factorial cache
     * @param maxN Maximum value to cache
     * @param mod Modulus
     */
    static void initialize(int maxN = MAX_CACHE, ll mod = MOD) {
        if (initialized) return;
        
        factCache.resize(maxN + 1);
        factCache[0] = 1;
        
        for (int i = 1; i <= maxN; i++) {
            factCache[i] = ModularArithmetic::multiply(factCache[i - 1], i, mod);
        }
        
        initialized = true;
    }
    
    /**
     * @brief Calculate factorial n!
     * @param n Number
     * @param mod Modulus
     * @return n! % mod
     */
    static ll factorial(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n < sz(factCache)) {
            initialize(n, mod);
            return factCache[n];
        }
        
        ll result = 1;
        for (int i = 2; i <= n; i++) {
            result = ModularArithmetic::multiply(result, i, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate double factorial n!!
     * @param n Number
     * @param mod Modulus
     * @return n!! % mod
     */
    static ll doubleFactorial(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = 1;
        for (int i = n; i > 0; i -= 2) {
            result = ModularArithmetic::multiply(result, i, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate rising factorial (x)^(n)
     * @param x Base
     * @param n Exponent
     * @param mod Modulus
     * @return (x)^(n) % mod
     */
    static ll risingFactorial(ll x, int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        ll result = 1;
        for (int i = 0; i < n; i++) {
            result = ModularArithmetic::multiply(result, (x + i) % mod, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate falling factorial (x)_n
     * @param x Base
     * @param n Exponent
     * @param mod Modulus
     * @return (x)_n % mod
     */
    static ll fallingFactorial(ll x, int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        ll result = 1;
        for (int i = 0; i < n; i++) {
            result = ModularArithmetic::multiply(result, (x - i) % mod, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate factorial with prime factorization
     * @param n Number
     * @return Map of prime factors and their powers
     */
    static map<int, int> factorialFactorization(int n) {
        map<int, int> factors;
        
        for (int i = 2; i <= n; i++) {
            int temp = i;
            for (int j = 2; j * j <= temp; j++) {
                while (temp % j == 0) {
                    factors[j]++;
                    temp /= j;
                }
            }
            if (temp > 1) {
                factors[temp]++;
            }
        }
        
        return factors;
    }
    
    /**
     * @brief Calculate number of trailing zeros in n!
     * @param n Number
     * @return Number of trailing zeros
     */
    static int trailingZeros(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i;
        }
        return count;
    }
    
    /**
     * @brief Calculate last non-zero digit of n!
     * @param n Number
     * @return Last non-zero digit
     */
    static int lastNonZeroDigit(int n) {
        if (n <= 1) return 1;
        
        vector<int> digits = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
        
        if (n < 10) return digits[n];
        
        if ((n / 10) % 2 == 0) {
            return (6 * lastNonZeroDigit(n / 5) * digits[n % 10]) % 10;
        } else {
            return (4 * lastNonZeroDigit(n / 5) * digits[n % 10]) % 10;
        }
    }
    
    /**
     * @brief Check if n! is divisible by m
     * @param n Number
     * @param m Divisor
     * @return true if n! is divisible by m
     */
    static bool isDivisibleBy(int n, int m) {
        if (m <= 1) return true;
        if (n < 0) return false;
        
        map<int, int> mFactors;
        int temp = m;
        for (int i = 2; i * i <= temp; i++) {
            while (temp % i == 0) {
                mFactors[i]++;
                temp /= i;
            }
        }
        if (temp > 1) mFactors[temp]++;
        
        for (auto& factor : mFactors) {
            int prime = factor.first;
            int power = factor.second;
            
            int count = 0;
            int temp = n;
            while (temp > 0) {
                count += temp / prime;
                temp /= prime;
            }
            
            if (count < power) return false;
        }
        
        return true;
    }
    
    /**
     * @brief Calculate Wilson's theorem: (p-1)! ≡ -1 (mod p) for prime p
     * @param p Prime number
     * @param mod Modulus
     * @return (p-1)! % mod
     */
    static ll wilsonTheorem(int p, ll mod = MOD) {
        if (p <= 1) return 1;
        return ModularArithmetic::subtract(mod, 1, mod); // -1 mod p
    }
    
    /**
     * @brief Calculate superfactorial: ∏(k!) for k from 1 to n
     * @param n Number
     * @param mod Modulus
     * @return Superfactorial % mod
     */
    static ll superFactorial(int n, ll mod = MOD) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        
        ll result = 1;
        for (int i = 1; i <= n; i++) {
            result = ModularArithmetic::multiply(result, factorial(i, mod), mod);
        }
        return result;
    }
};

// Static member definitions
vector<ll> Factorial::factCache;
bool Factorial::initialized = false;

#endif // FACTORIAL_HPP
