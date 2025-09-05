/**
 * @file ternary_search.hpp
 * @brief Ternary Search Algorithms
 * 
 * This header provides implementations for ternary search
 * on unimodal functions and arrays.
 * 
 * Features:
 * - Ternary search on arrays
 * - Ternary search on functions
 * - Real number ternary search
 * - Integer ternary search
 * - Custom comparator support
 * 
 * Time Complexity: O(log n) base 3
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef TERNARY_SEARCH_HPP
#define TERNARY_SEARCH_HPP

#include "utilities/common.hpp"

class TernarySearch {
public:
    /**
     * @brief Find maximum in unimodal array
     * @param arr Unimodal array
     * @return Index of maximum element
     */
    static int findMaximum(const vector<int>& arr) {
        int left = 0, right = sz(arr) - 1;
        
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            if (arr[mid1] < arr[mid2]) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        
        int maxIdx = left;
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        
        return maxIdx;
    }
    
    /**
     * @brief Find minimum in unimodal array
     * @param arr Unimodal array
     * @return Index of minimum element
     */
    static int findMinimum(const vector<int>& arr) {
        int left = 0, right = sz(arr) - 1;
        
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            if (arr[mid1] > arr[mid2]) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        
        int minIdx = left;
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
        }
        
        return minIdx;
    }
    
    /**
     * @brief Find maximum value in unimodal array
     * @param arr Unimodal array
     * @return Maximum value
     */
    static int findMaximumValue(const vector<int>& arr) {
        int idx = findMaximum(arr);
        return arr[idx];
    }
    
    /**
     * @brief Find minimum value in unimodal array
     * @param arr Unimodal array
     * @return Minimum value
     */
    static int findMinimumValue(const vector<int>& arr) {
        int idx = findMinimum(arr);
        return arr[idx];
    }
    
    /**
     * @brief Ternary search on real numbers
     * @param func Function to search
     * @param left Left bound
     * @param right Right bound
     * @param precision Desired precision
     * @return X coordinate of maximum
     */
    static double realTernarySearch(double (*func)(double), double left, double right, double precision = 1e-9) {
        while (right - left > precision) {
            double mid1 = left + (right - left) / 3.0;
            double mid2 = right - (right - left) / 3.0;
            
            if (func(mid1) < func(mid2)) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        
        return (left + right) / 2.0;
    }
    
    /**
     * @brief Ternary search on real numbers for minimum
     * @param func Function to search
     * @param left Left bound
     * @param right Right bound
     * @param precision Desired precision
     * @return X coordinate of minimum
     */
    static double realTernarySearchMin(double (*func)(double), double left, double right, double precision = 1e-9) {
        while (right - left > precision) {
            double mid1 = left + (right - left) / 3.0;
            double mid2 = right - (right - left) / 3.0;
            
            if (func(mid1) > func(mid2)) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        
        return (left + right) / 2.0;
    }
    
    /**
     * @brief Find peak in 1D array
     * @param arr Array
     * @return Index of peak element
     */
    static int findPeak(const vector<int>& arr) {
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
    
    /**
     * @brief Find valley in 1D array
     * @param arr Array
     * @return Index of valley element
     */
    static int findValley(const vector<int>& arr) {
        int left = 0, right = sz(arr) - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    /**
     * @brief Check if array is unimodal
     * @param arr Array to check
     * @return true if unimodal
     */
    static bool isUnimodal(const vector<int>& arr) {
        if (sz(arr) < 3) return true;
        
        bool increasing = true;
        bool decreasing = false;
        
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] > arr[i-1]) {
                if (decreasing) return false;
            } else if (arr[i] < arr[i-1]) {
                decreasing = true;
            }
        }
        
        return true;
    }
    
    /**
     * @brief Find inflection point in unimodal array
     * @param arr Unimodal array
     * @return Index of inflection point
     */
    static int findInflectionPoint(const vector<int>& arr) {
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
    
    /**
     * @brief Find maximum with custom comparator
     * @param arr Array
     * @param comp Comparator function
     * @return Index of maximum element
     */
    static int findMaximumCustom(const vector<int>& arr, bool (*comp)(int, int)) {
        int left = 0, right = sz(arr) - 1;
        
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            if (comp(arr[mid1], arr[mid2])) {
                left = mid1;
            } else {
                right = mid2;
            }
        }
        
        int maxIdx = left;
        for (int i = left + 1; i <= right; i++) {
            if (comp(arr[i], arr[maxIdx])) {
                maxIdx = i;
            }
        }
        
        return maxIdx;
    }
};

#endif // TERNARY_SEARCH_HPP
