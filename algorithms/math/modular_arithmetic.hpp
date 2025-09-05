/**
 * @file modular_arithmetic.hpp
 * @brief Modular Arithmetic Operations
 * 
 * This header provides comprehensive modular arithmetic operations
 * optimized for competitive programming.
 * 
 * Features:
 * - Modular addition, subtraction, multiplication
 * - Modular exponentiation
 * - Modular inverse
 * - Chinese Remainder Theorem
 * - Wilson's theorem
 * - Fermat's little theorem
 * 
 * Time Complexity: O(log n) for most operations
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef MODULAR_ARITHMETIC_HPP
#define MODULAR_ARITHMETIC_HPP

#include "utilities/common.hpp"

class ModularArithmetic {
public:
    /**
     * @brief Safe modular addition
     * @param a First number
     * @param b Second number
     * @param mod Modulus
     * @return (a + b) % mod
     */
    static ll add(ll a, ll b, ll mod = MOD) {
        return ((a % mod) + (b % mod)) % mod;
    }
    
    /**
     * @brief Safe modular subtraction
     * @param a First number
     * @param b Second number
     * @param mod Modulus
     * @return (a - b) % mod
     */
    static ll subtract(ll a, ll b, ll mod = MOD) {
        return ((a % mod) - (b % mod) + mod) % mod;
    }
    
    /**
     * @brief Safe modular multiplication
     * @param a First number
     * @param b Second number
     * @param mod Modulus
     * @return (a * b) % mod
     */
    static ll multiply(ll a, ll b, ll mod = MOD) {
        return ((a % mod) * (b % mod)) % mod;
    }
    
    /**
     * @brief Modular exponentiation using binary exponentiation
     * @param base Base number
     * @param exponent Exponent
     * @param mod Modulus
     * @return (base^exponent) % mod
     */
    static ll power(ll base, ll exponent, ll mod = MOD) {
        ll result = 1;
        base %= mod;
        
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent >>= 1;
        }
        
        return result;
    }
    
    /**
     * @brief Modular inverse using Fermat's little theorem
     * @param a Number
     * @param mod Modulus (must be prime)
     * @return Modular inverse of a mod mod
     */
    static ll modInverse(ll a, ll mod = MOD) {
        return power(a, mod - 2, mod);
    }
    
    /**
     * @brief Modular division
     * @param a Dividend
     * @param b Divisor
     * @param mod Modulus
     * @return (a / b) % mod
     */
    static ll divide(ll a, ll b, ll mod = MOD) {
        return multiply(a, modInverse(b, mod), mod);
    }
    
    /**
     * @brief Calculate factorial modulo mod
     * @param n Number
     * @param mod Modulus
     * @return n! % mod
     */
    static ll factorial(ll n, ll mod = MOD) {
        ll result = 1;
        for (ll i = 2; i <= n; i++) {
            result = multiply(result, i, mod);
        }
        return result;
    }
    
    /**
     * @brief Calculate combination C(n, r) modulo mod
     * @param n Total items
     * @param r Items to choose
     * @param mod Modulus
     * @return C(n, r) % mod
     */
    static ll combination(ll n, ll r, ll mod = MOD) {
        if (r > n || r < 0) return 0;
        if (r == 0 || r == n) return 1;
        
        ll numerator = 1;
        ll denominator = 1;
        
        for (ll i = 0; i < r; i++) {
            numerator = multiply(numerator, n - i, mod);
            denominator = multiply(denominator, i + 1, mod);
        }
        
        return divide(numerator, denominator, mod);
    }
    
    /**
     * @brief Chinese Remainder Theorem
     * @param remainders Vector of remainders
     * @param moduli Vector of moduli
     * @return Solution x such that x ≡ remainders[i] (mod moduli[i])
     */
    static ll chineseRemainderTheorem(const vi& remainders, const vi& moduli) {
        int n = sz(remainders);
        if (n != sz(moduli)) return -1;
        
        ll result = 0;
        ll product = 1;
        
        for (int i = 0; i < n; i++) {
            product *= moduli[i];
        }
        
        for (int i = 0; i < n; i++) {
            ll pp = product / moduli[i];
            ll inv = modInverse(pp, moduli[i]);
            result = add(result, multiply(multiply(remainders[i], pp, product), inv, product), product);
        }
        
        return result;
    }
    
    /**
     * @brief Check if a number is prime using Fermat's test
     * @param n Number to check
     * @param iterations Number of test iterations
     * @return true if probably prime, false if composite
     */
    static bool isPrimeFermat(ll n, int iterations = 5) {
        if (n <= 1 || n == 4) return false;
        if (n <= 3) return true;
        
        for (int i = 0; i < iterations; i++) {
            ll a = 2 + rand() % (n - 4);
            if (power(a, n - 1, n) != 1) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Calculate Euler's totient function
     * @param n Number
     * @return φ(n)
     */
    static ll eulerTotient(ll n) {
        ll result = n;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                result -= result / i;
            }
        }
        if (n > 1) {
            result -= result / n;
        }
        return result;
    }
};

#endif // MODULAR_ARITHMETIC_HPP
