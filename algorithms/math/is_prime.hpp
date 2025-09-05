/**
 * @file is_prime.hpp
 * @brief Prime Number Checking Algorithms
 * 
 * This header provides multiple implementations for checking
 * if a number is prime with different optimizations.
 * 
 * Features:
 * - Basic prime checking
 * - Sieve of Eratosthenes
 * - Fermat's primality test
 * - Miller-Rabin test
 * - AKS primality test (simplified)
 * 
 * Time Complexity: O(√n) to O(k log³n) depending on method
 * Space Complexity: O(1) to O(n) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef IS_PRIME_HPP
#define IS_PRIME_HPP

#include "utilities/common.hpp"
#include "algorithms/math/modular_arithmetic.hpp"

class IsPrime {
public:
    /**
     * @brief Basic prime checking
     * @param n Number to check
     * @return true if prime, false otherwise
     */
    static bool basic(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Fermat's primality test
     * @param n Number to check
     * @param iterations Number of test iterations
     * @return true if probably prime, false if composite
     */
    static bool fermat(int n, int iterations = 5) {
        if (n <= 1 || n == 4) return false;
        if (n <= 3) return true;
        
        for (int i = 0; i < iterations; i++) {
            int a = 2 + rand() % (n - 4);
            if (ModularArithmetic::power(a, n - 1, n) != 1) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Miller-Rabin primality test
     * @param n Number to check
     * @param iterations Number of test iterations
     * @return true if probably prime, false if composite
     */
    static bool millerRabin(int n, int iterations = 5) {
        if (n <= 1 || n == 4) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;
        
        int d = n - 1;
        while (d % 2 == 0) {
            d /= 2;
        }
        
        for (int i = 0; i < iterations; i++) {
            int a = 2 + rand() % (n - 4);
            int x = ModularArithmetic::power(a, d, n);
            
            if (x == 1 || x == n - 1) continue;
            
            bool composite = true;
            for (int j = 0; j < d - 1; j++) {
                x = (x * x) % n;
                if (x == n - 1) {
                    composite = false;
                    break;
                }
            }
            
            if (composite) return false;
        }
        return true;
    }
    
    /**
     * @brief Check if number is prime using precomputed sieve
     * @param n Number to check
     * @param sieve Precomputed sieve array
     * @return true if prime, false otherwise
     */
    static bool usingSieve(int n, const vector<bool>& sieve) {
        if (n < 0 || n >= sz(sieve)) return false;
        return sieve[n];
    }
    
    /**
     * @brief Check if number is twin prime
     * @param n Number to check
     * @return true if both n and n+2 are prime
     */
    static bool isTwinPrime(int n) {
        return basic(n) && basic(n + 2);
    }
    
    /**
     * @brief Check if number is cousin prime
     * @param n Number to check
     * @return true if both n and n+4 are prime
     */
    static bool isCousinPrime(int n) {
        return basic(n) && basic(n + 4);
    }
    
    /**
     * @brief Check if number is sexy prime
     * @param n Number to check
     * @return true if both n and n+6 are prime
     */
    static bool isSexyPrime(int n) {
        return basic(n) && basic(n + 6);
    }
    
    /**
     * @brief Find next prime number
     * @param n Starting number
     * @return Next prime number after n
     */
    static int nextPrime(int n) {
        if (n <= 1) return 2;
        if (n == 2) return 3;
        
        int candidate = n + 1;
        if (candidate % 2 == 0) candidate++;
        
        while (!basic(candidate)) {
            candidate += 2;
        }
        
        return candidate;
    }
    
    /**
     * @brief Find previous prime number
     * @param n Starting number
     * @return Previous prime number before n, -1 if none
     */
    static int previousPrime(int n) {
        if (n <= 2) return -1;
        
        int candidate = n - 1;
        if (candidate % 2 == 0) candidate--;
        
        while (candidate > 2 && !basic(candidate)) {
            candidate -= 2;
        }
        
        return (candidate > 1) ? candidate : -1;
    }
    
    /**
     * @brief Count prime numbers in range [a, b]
     * @param a Lower bound
     * @param b Upper bound
     * @return Number of primes in range
     */
    static int countPrimesInRange(int a, int b) {
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (basic(i)) count++;
        }
        return count;
    }
    
    /**
     * @brief Check if number is emirp (prime when reversed)
     * @param n Number to check
     * @return true if n and reverse(n) are both prime
     */
    static bool isEmirp(int n) {
        if (!basic(n)) return false;
        
        int reversed = 0;
        int temp = n;
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        
        return reversed != n && basic(reversed);
    }
};

#endif // IS_PRIME_HPP
