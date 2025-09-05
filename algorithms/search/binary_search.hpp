/**
 * @file binary_search.hpp
 * @brief Binary Search Algorithms and Variants
 * 
 * This header provides comprehensive implementations of binary search algorithms
 * and their variants commonly used in competitive programming.
 * 
 * Features:
 * - Standard binary search
 * - Lower bound and upper bound
 * - Binary search on answer
 * - Binary search on real numbers
 * - Custom predicate binary search
 * - Square root and nth root
 * - Peak element finding
 * 
 * Time Complexity: O(log n) for most operations
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include "utilities/common.hpp"

class BinarySearch {
public:
    /**
     * @brief Standard binary search for a target value
     * @param arr Sorted array to search in
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     */
    static int search(const vi& arr, int target) {
        int left = 0, right = sz(arr) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    /**
     * @brief Find the first position where target can be inserted (lower bound)
     * @param arr Sorted array
     * @param target Value to find lower bound for
     * @return Index of first element >= target
     */
    static int lowerBound(const vi& arr, int target) {
        int left = 0, right = sz(arr);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    /**
     * @brief Find the first position where target can be inserted (upper bound)
     * @param arr Sorted array
     * @param target Value to find upper bound for
     * @return Index of first element > target
     */
    static int upperBound(const vi& arr, int target) {
        int left = 0, right = sz(arr);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    /**
     * @brief Binary search on answer for optimization problems
     * @param left Left boundary of search space
     * @param right Right boundary of search space
     * @param predicate Function that returns true for valid answers
     * @return Maximum value for which predicate returns true
     */
    static int binarySearchOnAnswer(int left, int right, function<bool(int)> predicate) {
        int result = left;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (predicate(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    /**
     * @brief Binary search on real numbers
     * @param left Left boundary of search space
     * @param right Right boundary of search space
     * @param predicate Function that returns true for valid answers
     * @param precision Desired precision (default: 1e-9)
     * @return Value for which predicate is satisfied with given precision
     */
    static double binarySearchReal(double left, double right, function<bool(double)> predicate, double precision = 1e-9) {
        while (right - left > precision) {
            double mid = (left + right) / 2.0;
            
            if (predicate(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return (left + right) / 2.0;
    }
    
    /**
     * @brief Find square root using binary search
     * @param n Number to find square root of
     * @param precision Desired precision (default: 1e-9)
     * @return Square root of n
     */
    static double sqrt(int n, double precision = 1e-9) {
        if (n < 0) return -1; // Invalid input
        
        double left = 0, right = n;
        if (n < 1) right = 1;
        
        return binarySearchReal(left, right, [n](double x) {
            return x * x >= n;
        }, precision);
    }
    
    /**
     * @brief Find nth root using binary search
     * @param n Number to find root of
     * @param root Root degree (e.g., 3 for cube root)
     * @param precision Desired precision (default: 1e-9)
     * @return nth root of n
     */
    static double nthRoot(int n, int root, double precision = 1e-9) {
        if (n < 0 && root % 2 == 0) return -1; // Invalid input
        
        double left = 0, right = n;
        if (n < 1) right = 1;
        if (n < 0) {
            left = n;
            right = 0;
        }
        
        return binarySearchReal(left, right, [n, root](double x) {
            double result = 1;
            for (int i = 0; i < root; i++) {
                result *= x;
            }
            return result >= n;
        }, precision);
    }
    
    /**
     * @brief Find peak element in array using binary search
     * @param arr Array to search in
     * @return Index of peak element
     * 
     * A peak element is greater than or equal to its neighbors.
     */
    static int findPeak(const vi& arr) {
        int left = 0, right = sz(arr) - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};

#endif // BINARY_SEARCH_HPP
