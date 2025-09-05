/**
 * @file square_root.hpp
 * @brief Square Root Algorithms
 * 
 * This header provides multiple implementations for calculating
 * square roots with different methods and precisions.
 * 
 * Features:
 * - Binary search square root
 * - Newton's method
 * - Babylonian method
 * - Integer square root
 * - Perfect square checking
 * - Square root with precision
 * 
 * Time Complexity: O(log n) to O(log(1/ε)) depending on method
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef SQUARE_ROOT_HPP
#define SQUARE_ROOT_HPP

#include "utilities/common.hpp"

class SquareRoot {
public:
    /**
     * @brief Calculate square root using binary search
     * @param n Number
     * @param precision Desired precision
     * @return Square root of n
     */
    static double binarySearch(double n, double precision = 1e-9) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        if (n < 1) return binarySearch(1.0 / n, precision) / n;
        
        double left = 0, right = n;
        if (n < 1) right = 1;
        
        while (right - left > precision) {
            double mid = (left + right) / 2.0;
            if (mid * mid < n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return (left + right) / 2.0;
    }
    
    /**
     * @brief Calculate square root using Newton's method
     * @param n Number
     * @param precision Desired precision
     * @return Square root of n
     */
    static double newtonMethod(double n, double precision = 1e-9) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        
        double x = n;
        double prev;
        
        do {
            prev = x;
            x = (x + n / x) / 2.0;
        } while (abs(x - prev) > precision);
        
        return x;
    }
    
    /**
     * @brief Calculate square root using Babylonian method
     * @param n Number
     * @param precision Desired precision
     * @return Square root of n
     */
    static double babylonianMethod(double n, double precision = 1e-9) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        
        double x = n;
        double y = 1;
        
        while (x - y > precision) {
            x = (x + y) / 2.0;
            y = n / x;
        }
        
        return x;
    }
    
    /**
     * @brief Calculate integer square root
     * @param n Number
     * @return Integer square root of n
     */
    static int integerSqrt(int n) {
        if (n < 0) return -1; // Invalid input
        if (n <= 1) return n;
        
        int left = 1, right = n;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (mid <= n / mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    /**
     * @brief Check if number is perfect square
     * @param n Number to check
     * @return true if n is perfect square
     */
    static bool isPerfectSquare(int n) {
        if (n < 0) return false;
        if (n <= 1) return true;
        
        int sqrt = integerSqrt(n);
        return sqrt * sqrt == n;
    }
    
    /**
     * @brief Find next perfect square
     * @param n Starting number
     * @return Next perfect square after n
     */
    static int nextPerfectSquare(int n) {
        if (n < 0) return 0;
        
        int sqrt = integerSqrt(n);
        if (sqrt * sqrt == n) {
            return (sqrt + 1) * (sqrt + 1);
        } else {
            return (sqrt + 1) * (sqrt + 1);
        }
    }
    
    /**
     * @brief Find previous perfect square
     * @param n Starting number
     * @return Previous perfect square before n, -1 if none
     */
    static int previousPerfectSquare(int n) {
        if (n <= 0) return -1;
        
        int sqrt = integerSqrt(n);
        if (sqrt * sqrt == n) {
            sqrt--;
        }
        
        return (sqrt > 0) ? sqrt * sqrt : -1;
    }
    
    /**
     * @brief Calculate square root with custom precision
     * @param n Number
     * @param precision Desired precision
     * @param maxIterations Maximum iterations
     * @return Square root of n
     */
    static double customPrecision(double n, double precision = 1e-9, int maxIterations = 1000) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        
        double x = n;
        int iterations = 0;
        
        while (iterations < maxIterations) {
            double prev = x;
            x = (x + n / x) / 2.0;
            
            if (abs(x - prev) < precision) {
                break;
            }
            iterations++;
        }
        
        return x;
    }
    
    /**
     * @brief Calculate square root using continued fractions
     * @param n Number
     * @param iterations Number of iterations
     * @return Square root of n
     */
    static double continuedFraction(double n, int iterations = 10) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        
        double result = 1;
        for (int i = 0; i < iterations; i++) {
            result = 1 + n / (1 + result);
        }
        
        return result;
    }
    
    /**
     * @brief Calculate square root using Taylor series
     * @param n Number
     * @param terms Number of terms in series
     * @return Square root of n
     */
    static double taylorSeries(double n, int terms = 10) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // Use Taylor series around x = 1
        double x = n - 1;
        double result = 1;
        double term = 1;
        
        for (int i = 1; i < terms; i++) {
            term *= (-1) * (2 * i - 3) * x / (2 * i);
            result += term;
        }
        
        return result;
    }
    
    /**
     * @brief Calculate square root using Heron's method
     * @param n Number
     * @param precision Desired precision
     * @return Square root of n
     */
    static double heronMethod(double n, double precision = 1e-9) {
        if (n < 0) return -1; // Invalid input
        if (n == 0) return 0;
        
        double x = n;
        double prev;
        
        do {
            prev = x;
            x = 0.5 * (x + n / x);
        } while (abs(x - prev) > precision);
        
        return x;
    }
};

#endif // SQUARE_ROOT_HPP
