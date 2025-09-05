/**
 * @file divisors.hpp
 * @brief Divisor and Factor Algorithms
 * 
 * This header provides multiple implementations for finding
 * divisors and factors of numbers with different optimizations.
 * 
 * Features:
 * - Find all divisors
 * - Count divisors
 * - Sum of divisors
 * - Prime factorization
 * - Greatest common divisor
 * - Least common multiple
 * 
 * Time Complexity: O(√n) to O(n) depending on method
 * Space Complexity: O(1) to O(√n) depending on method
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef DIVISORS_HPP
#define DIVISORS_HPP

#include "utilities/common.hpp"
#include "algorithms/math/prime_sieve.hpp"

class Divisors {
public:
    /**
     * @brief Find all divisors of a number
     * @param n Number
     * @return Vector of all divisors
     */
    static vector<int> findAllDivisors(int n) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
    
    /**
     * @brief Count number of divisors
     * @param n Number
     * @return Number of divisors
     */
    static int countDivisors(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                count++;
                if (i != n / i) {
                    count++;
                }
            }
        }
        return count;
    }
    
    /**
     * @brief Sum of all divisors
     * @param n Number
     * @return Sum of divisors
     */
    static long long sumOfDivisors(int n) {
        long long sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }
        return sum;
    }
    
    /**
     * @brief Find prime factors of a number
     * @param n Number
     * @return Vector of prime factors with their counts
     */
    static vector<pair<int, int>> primeFactorization(int n) {
        vector<pair<int, int>> factors;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                factors.push_back({i, count});
            }
        }
        
        if (n > 1) {
            factors.push_back({n, 1});
        }
        
        return factors;
    }
    
    /**
     * @brief Count divisors using prime factorization
     * @param n Number
     * @return Number of divisors
     */
    static int countDivisorsOptimized(int n) {
        vector<pair<int, int>> factors = primeFactorization(n);
        int count = 1;
        
        for (auto& factor : factors) {
            count *= (factor.second + 1);
        }
        
        return count;
    }
    
    /**
     * @brief Sum of divisors using prime factorization
     * @param n Number
     * @return Sum of divisors
     */
    static long long sumOfDivisorsOptimized(int n) {
        vector<pair<int, int>> factors = primeFactorization(n);
        long long sum = 1;
        
        for (auto& factor : factors) {
            long long term = 1;
            long long power = 1;
            for (int i = 0; i <= factor.second; i++) {
                term += power;
                power *= factor.first;
            }
            sum *= term;
        }
        
        return sum;
    }
    
    /**
     * @brief Find proper divisors (excluding the number itself)
     * @param n Number
     * @return Vector of proper divisors
     */
    static vector<int> findProperDivisors(int n) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != n) {
                    divisors.push_back(i);
                }
                if (i != n / i && n / i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
    
    /**
     * @brief Check if number is perfect (sum of proper divisors equals number)
     * @param n Number
     * @return true if perfect number
     */
    static bool isPerfect(int n) {
        if (n <= 1) return false;
        return sumOfDivisors(n) - n == n;
    }
    
    /**
     * @brief Check if number is abundant (sum of proper divisors > number)
     * @param n Number
     * @return true if abundant number
     */
    static bool isAbundant(int n) {
        if (n <= 1) return false;
        return sumOfDivisors(n) - n > n;
    }
    
    /**
     * @brief Check if number is deficient (sum of proper divisors < number)
     * @param n Number
     * @return true if deficient number
     */
    static bool isDeficient(int n) {
        if (n <= 1) return false;
        return sumOfDivisors(n) - n < n;
    }
    
    /**
     * @brief Find greatest common divisor
     * @param a First number
     * @param b Second number
     * @return GCD of a and b
     */
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    /**
     * @brief Find least common multiple
     * @param a First number
     * @param b Second number
     * @return LCM of a and b
     */
    static long long lcm(int a, int b) {
        return (long long)a * b / gcd(a, b);
    }
    
    /**
     * @brief Find GCD of multiple numbers
     * @param numbers Vector of numbers
     * @return GCD of all numbers
     */
    static int gcdMultiple(const vector<int>& numbers) {
        if (numbers.empty()) return 0;
        
        int result = numbers[0];
        for (int i = 1; i < sz(numbers); i++) {
            result = gcd(result, numbers[i]);
        }
        return result;
    }
    
    /**
     * @brief Find LCM of multiple numbers
     * @param numbers Vector of numbers
     * @return LCM of all numbers
     */
    static long long lcmMultiple(const vector<int>& numbers) {
        if (numbers.empty()) return 0;
        
        long long result = numbers[0];
        for (int i = 1; i < sz(numbers); i++) {
            result = lcm(result, numbers[i]);
        }
        return result;
    }
    
    /**
     * @brief Check if two numbers are coprime
     * @param a First number
     * @param b Second number
     * @return true if coprime
     */
    static bool isCoprime(int a, int b) {
        return gcd(a, b) == 1;
    }
    
    /**
     * @brief Find number of coprime numbers <= n
     * @param n Number
     * @return Count of coprime numbers
     */
    static int countCoprimes(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isCoprime(i, n)) {
                count++;
            }
        }
        return count;
    }
};

#endif // DIVISORS_HPP
