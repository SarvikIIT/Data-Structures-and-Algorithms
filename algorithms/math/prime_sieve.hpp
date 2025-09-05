/**
 * @file prime_sieve.hpp
 * @brief Prime Sieve and Number Theory Algorithms
 * 
 * This header provides implementations of prime number algorithms
 * and related number theory functions.
 * 
 * Features:
 * - Sieve of Eratosthenes
 * - Segmented Sieve
 * - Prime factorization
 * - GCD and LCM
 * - Modular arithmetic
 * - Prime checking
 * 
 * Time Complexity:
 * - Sieve: O(n log log n)
 * - Prime check: O(√n)
 * - Factorization: O(√n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef PRIME_SIEVE_HPP
#define PRIME_SIEVE_HPP

#include "utilities/common.hpp"

class PrimeSieve {
private:
    static const int MAX_VAL = 1000000;
    static vector<bool> isPrime;
    static vi primes;
    static bool initialized;
    
public:
    /**
     * @brief Initialize sieve for primes up to MAX_VAL
     */
    static void initialize() {
        if (initialized) return;
        
        isPrime.assign(MAX_VAL + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= MAX_VAL; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX_VAL; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 2; i <= MAX_VAL; i++) {
            if (isPrime[i]) {
                primes.pb(i);
            }
        }
        
        initialized = true;
    }
    
    /**
     * @brief Check if a number is prime
     * @param n Number to check
     * @return true if prime, false otherwise
     */
    static bool isPrimeNumber(int n) {
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
     * @brief Get all primes up to n
     * @param n Upper limit
     * @return Vector of primes
     */
    static vi getPrimes(int n) {
        initialize();
        vi result;
        for (int prime : primes) {
            if (prime > n) break;
            result.pb(prime);
        }
        return result;
    }
    
    /**
     * @brief Get nth prime number
     * @param n Position (1-indexed)
     * @return nth prime number
     */
    static int getNthPrime(int n) {
        initialize();
        if (n > sz(primes)) return -1;
        return primes[n - 1];
    }
    
    /**
     * @brief Prime factorization of a number
     * @param n Number to factorize
     * @return Vector of prime factors with their powers
     */
    static vector<pii> primeFactorization(int n) {
        vector<pii> factors;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                factors.pb({i, count});
            }
        }
        
        if (n > 1) {
            factors.pb({n, 1});
        }
        
        return factors;
    }
    
    /**
     * @brief Segmented sieve for large ranges
     * @param low Lower bound
     * @param high Upper bound
     * @return Vector of primes in range [low, high]
     */
    static vi segmentedSieve(int low, int high) {
        int limit = sqrt(high) + 1;
        vector<bool> mark(limit + 1, false);
        vi primes;
        
        // Generate primes up to sqrt(high)
        for (int i = 2; i <= limit; i++) {
            if (!mark[i]) {
                primes.pb(i);
                for (int j = i * i; j <= limit; j += i) {
                    mark[j] = true;
                }
            }
        }
        
        // Segmented sieve
        vector<bool> isPrime(high - low + 1, true);
        
        for (int prime : primes) {
            int start = max(prime * prime, (low + prime - 1) / prime * prime);
            for (int j = start; j <= high; j += prime) {
                isPrime[j - low] = false;
            }
        }
        
        if (low == 1) isPrime[0] = false;
        
        vi result;
        for (int i = 0; i < sz(isPrime); i++) {
            if (isPrime[i]) {
                result.pb(low + i);
            }
        }
        
        return result;
    }
    
    /**
     * @brief Count prime numbers up to n
     * @param n Upper limit
     * @return Number of primes up to n
     */
    static int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int count = 0;
        for (bool prime : isPrime) {
            if (prime) count++;
        }
        
        return count;
    }
    
    /**
     * @brief Get all divisors of a number
     * @param n Number to find divisors for
     * @return Vector of divisors
     */
    static vi getDivisors(int n) {
        vi divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.pb(i);
                if (i != n / i) {
                    divisors.pb(n / i);
                }
            }
        }
        sort(all(divisors));
        return divisors;
    }
    
    /**
     * @brief Calculate Euler's Totient Function
     * @param n Number to calculate phi for
     * @return Value of phi(n)
     */
    static int eulerTotient(int n) {
        int result = n;
        for (int i = 2; i * i <= n; i++) {
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

// Static member definitions
vector<bool> PrimeSieve::isPrime;
vi PrimeSieve::primes;
bool PrimeSieve::initialized = false;

#endif // PRIME_SIEVE_HPP
