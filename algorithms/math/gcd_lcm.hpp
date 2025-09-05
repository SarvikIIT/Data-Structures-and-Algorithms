/**
 * @file gcd_lcm.hpp
 * @brief GCD and LCM Algorithms
 * 
 * This header provides implementations of GCD and LCM algorithms
 * with various optimizations and related functions.
 * 
 * Features:
 * - Euclidean GCD algorithm
 * - Extended Euclidean algorithm
 * - LCM calculation
 * - Binary GCD algorithm
 * - Modular inverse
 * 
 * Time Complexity: O(log min(a, b))
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef GCD_LCM_HPP
#define GCD_LCM_HPP

#include "utilities/common.hpp"

class GCDLCM {
public:
    /**
     * @brief Calculate GCD using Euclidean algorithm
     * @param a First number
     * @param b Second number
     * @return GCD of a and b
     */
    static ll gcd(ll a, ll b) {
        if (b > a) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    /**
     * @brief Calculate GCD using iterative approach
     * @param a First number
     * @param b Second number
     * @return GCD of a and b
     */
    static ll gcdIterative(ll a, ll b) {
        while (b != 0) {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    /**
     * @brief Calculate LCM of two numbers
     * @param a First number
     * @param b Second number
     * @return LCM of a and b
     */
    static ll lcm(ll a, ll b) {
        return (a * b) / gcd(a, b);
    }
    
    /**
     * @brief Extended Euclidean algorithm
     * @param a First number
     * @param b Second number
     * @return Tuple of (gcd, x, y) where ax + by = gcd(a, b)
     */
    static tuple<ll, ll, ll> extendedGcd(ll a, ll b) {
        if (b == 0) {
            return {a, 1, 0};
        }
        
        auto [gcd, x1, y1] = extendedGcd(b, a % b);
        ll x = y1;
        ll y = x1 - (a / b) * y1;
        
        return {gcd, x, y};
    }
    
    /**
     * @brief Calculate modular inverse using extended Euclidean
     * @param a Number
     * @param m Modulus
     * @return Modular inverse of a mod m, -1 if doesn't exist
     */
    static ll modInverse(ll a, ll m) {
        auto [gcd, x, y] = extendedGcd(a, m);
        if (gcd != 1) return -1; // Inverse doesn't exist
        return (x % m + m) % m;
    }
    
    /**
     * @brief Binary GCD algorithm (optimized)
     * @param a First number
     * @param b Second number
     * @return GCD of a and b
     */
    static ll binaryGcd(ll a, ll b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        int shift = 0;
        while (((a | b) & 1) == 0) {
            a >>= 1;
            b >>= 1;
            shift++;
        }
        
        while ((a & 1) == 0) a >>= 1;
        
        do {
            while ((b & 1) == 0) b >>= 1;
            if (a > b) swap(a, b);
            b -= a;
        } while (b != 0);
        
        return a << shift;
    }
    
    /**
     * @brief Calculate GCD of multiple numbers
     * @param numbers Vector of numbers
     * @return GCD of all numbers
     */
    static ll gcdMultiple(const vi& numbers) {
        if (numbers.empty()) return 0;
        
        ll result = numbers[0];
        for (int i = 1; i < sz(numbers); i++) {
            result = gcd(result, numbers[i]);
        }
        return result;
    }
    
    /**
     * @brief Calculate LCM of multiple numbers
     * @param numbers Vector of numbers
     * @return LCM of all numbers
     */
    static ll lcmMultiple(const vi& numbers) {
        if (numbers.empty()) return 0;
        
        ll result = numbers[0];
        for (int i = 1; i < sz(numbers); i++) {
            result = lcm(result, numbers[i]);
        }
        return result;
    }
};

#endif // GCD_LCM_HPP
