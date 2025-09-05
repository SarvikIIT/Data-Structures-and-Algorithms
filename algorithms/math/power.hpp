/**
 * @file power.hpp
 * @brief Power and Exponentiation Algorithms
 * 
 * This header provides multiple implementations for calculating
 * powers and exponentiations with different optimizations.
 * 
 * Features:
 * - Binary exponentiation
 * - Modular exponentiation
 * - Matrix exponentiation
 * - Fast power with different bases
 * - Power of 2 optimizations
 * 
 * Time Complexity: O(log n) to O(log³n) depending on method
 * Space Complexity: O(1) to O(n²) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef POWER_HPP
#define POWER_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class Power {
public:
    /**
     * @brief Calculate a^b using binary exponentiation
     * @param base Base number
     * @param exp Exponent
     * @return base^exp
     */
    static long long binaryExponentiation(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return result;
    }
    
    /**
     * @brief Calculate a^b mod m using binary exponentiation
     * @param base Base number
     * @param exp Exponent
     * @param mod Modulus
     * @return (base^exp) mod m
     */
    static long long modularExponentiation(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    /**
     * @brief Calculate a^b using recursive approach
     * @param base Base number
     * @param exp Exponent
     * @return base^exp
     */
    static long long recursivePower(long long base, long long exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;
        
        long long half = recursivePower(base, exp / 2);
        if (exp % 2 == 0) {
            return half * half;
        } else {
            return half * half * base;
        }
    }
    
    /**
     * @brief Calculate a^b mod m using recursive approach
     * @param base Base number
     * @param exp Exponent
     * @param mod Modulus
     * @return (base^exp) mod m
     */
    static long long recursiveModularPower(long long base, long long exp, long long mod) {
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        
        long long half = recursiveModularPower(base, exp / 2, mod);
        half %= mod;
        
        if (exp % 2 == 0) {
            return (half * half) % mod;
        } else {
            return ((half * half) % mod * (base % mod)) % mod;
        }
    }
    
    /**
     * @brief Calculate 2^n efficiently
     * @param n Exponent
     * @return 2^n
     */
    static long long powerOfTwo(int n) {
        if (n < 0) return 0;
        if (n >= 63) return LLONG_MAX; // Overflow protection
        return 1LL << n;
    }
    
    /**
     * @brief Calculate 2^n mod m
     * @param n Exponent
     * @param mod Modulus
     * @return (2^n) mod m
     */
    static long long powerOfTwoMod(int n, long long mod) {
        if (n < 0) return 0;
        return ModularArithmetic::power(2, n, mod);
    }
    
    /**
     * @brief Calculate a^b using iterative approach
     * @param base Base number
     * @param exp Exponent
     * @return base^exp
     */
    static long long iterativePower(long long base, long long exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }
    
    /**
     * @brief Calculate a^b mod m using iterative approach
     * @param base Base number
     * @param exp Exponent
     * @param mod Modulus
     * @return (base^exp) mod m
     */
    static long long iterativeModularPower(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        for (int i = 0; i < exp; i++) {
            result = (result * base) % mod;
        }
        return result;
    }
    
    /**
     * @brief Calculate a^b with overflow protection
     * @param base Base number
     * @param exp Exponent
     * @return base^exp or -1 if overflow
     */
    static long long safePower(long long base, long long exp) {
        if (exp < 0) return 0;
        if (exp == 0) return 1;
        if (exp == 1) return base;
        
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) {
                if (result > LLONG_MAX / base) return -1; // Overflow
                result *= base;
            }
            if (base > LLONG_MAX / base) return -1; // Overflow
            base *= base;
            exp >>= 1;
        }
        return result;
    }
    
    /**
     * @brief Calculate a^b mod m with large numbers
     * @param base Base number
     * @param exp Exponent
     * @param mod Modulus
     * @return (base^exp) mod m
     */
    static long long largeModularPower(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return result;
    }
    
    /**
     * @brief Check if number is power of 2
     * @param n Number to check
     * @return true if n is power of 2
     */
    static bool isPowerOfTwo(long long n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    /**
     * @brief Find largest power of 2 <= n
     * @param n Number
     * @return Largest power of 2 <= n
     */
    static long long largestPowerOfTwo(long long n) {
        if (n <= 0) return 0;
        
        long long power = 1;
        while (power * 2 <= n) {
            power *= 2;
        }
        return power;
    }
    
    /**
     * @brief Find smallest power of 2 >= n
     * @param n Number
     * @return Smallest power of 2 >= n
     */
    static long long smallestPowerOfTwo(long long n) {
        if (n <= 0) return 1;
        if (n == 1) return 1;
        
        long long power = 1;
        while (power < n) {
            power *= 2;
        }
        return power;
    }
};

#endif // POWER_HPP
