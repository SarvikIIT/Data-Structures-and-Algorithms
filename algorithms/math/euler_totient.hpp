/**
 * @file euler_totient.hpp
 * @brief Euler's Totient Function
 * 
 * This header provides implementations of Euler's totient function
 * and related number theory functions.
 * 
 * Features:
 * - Euler's totient function φ(n)
 * - Totient function for multiple numbers
 * - Totient function using sieve
 * - Sum of totients
 * - Totient function properties
 * 
 * Time Complexity: O(√n) for single number, O(n log log n) for sieve
 * Space Complexity: O(1) for single, O(n) for sieve
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef EULER_TOTIENT_HPP
#define EULER_TOTIENT_HPP

#include "utilities/common.hpp"

class EulerTotient {
public:
    /**
     * @brief Calculate Euler's totient function φ(n)
     * @param n Number
     * @return φ(n) - count of numbers from 1 to n that are coprime to n
     */
    static ll totient(ll n) {
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
    
    /**
     * @brief Calculate totient for multiple numbers using sieve
     * @param n Upper limit
     * @return Vector of totient values from 1 to n
     */
    static vi totientSieve(int n) {
        vi phi(n + 1);
        for (int i = 0; i <= n; i++) {
            phi[i] = i;
        }
        
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) { // i is prime
                for (int j = i; j <= n; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        
        return phi;
    }
    
    /**
     * @brief Calculate sum of totients from 1 to n
     * @param n Upper limit
     * @return Sum of φ(1) + φ(2) + ... + φ(n)
     */
    static ll sumOfTotients(int n) {
        vi phi = totientSieve(n);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += phi[i];
        }
        return sum;
    }
    
    /**
     * @brief Check if two numbers are coprime
     * @param a First number
     * @param b Second number
     * @return true if gcd(a, b) = 1, false otherwise
     */
    static bool isCoprime(ll a, ll b) {
        return __gcd(a, b) == 1;
    }
    
    /**
     * @brief Count numbers coprime to n in range [1, m]
     * @param n Number
     * @param m Upper limit of range
     * @return Count of numbers in [1, m] coprime to n
     */
    static ll countCoprimesInRange(ll n, ll m) {
        if (m == 0) return 0;
        if (m == 1) return 1;
        
        ll result = 0;
        for (ll i = 1; i <= m; i++) {
            if (isCoprime(i, n)) {
                result++;
            }
        }
        return result;
    }
    
    /**
     * @brief Get all prime factors of n
     * @param n Number
     * @return Vector of unique prime factors
     */
    static vi getPrimeFactors(ll n) {
        vi factors;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.pb(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            factors.pb(n);
        }
        return factors;
    }
    
    /**
     * @brief Calculate totient using prime factorization
     * @param n Number
     * @return φ(n) using φ(n) = n * ∏(1 - 1/p) for all prime factors p
     */
    static ll totientFromFactors(ll n) {
        vi factors = getPrimeFactors(n);
        ll result = n;
        
        for (ll factor : factors) {
            result = result / factor * (factor - 1);
        }
        
        return result;
    }
    
    /**
     * @brief Check if n is a perfect totient number
     * @param n Number to check
     * @return true if n equals sum of its iterated totients
     */
    static bool isPerfectTotient(ll n) {
        ll sum = 0;
        ll current = n;
        
        while (current != 1) {
            current = totient(current);
            sum += current;
        }
        
        return sum == n;
    }
    
    /**
     * @brief Find all perfect totient numbers up to n
     * @param n Upper limit
     * @return Vector of perfect totient numbers
     */
    static vi findPerfectTotients(int n) {
        vi result;
        for (int i = 1; i <= n; i++) {
            if (isPerfectTotient(i)) {
                result.pb(i);
            }
        }
        return result;
    }
};

#endif // EULER_TOTIENT_HPP
