/**
 * @file linear_search.hpp
 * @brief Linear Search Algorithms
 * 
 * This header provides implementations of linear search algorithms
 * and related search operations.
 * 
 * Features:
 * - Linear search
 * - Find all occurrences
 * - Find first/last occurrence
 * - Search in 2D arrays
 * - String searching
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include "utilities/common.hpp"

class LinearSearch {
public:
    /**
     * @brief Linear search for a target value
     * @param arr Array to search in
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     */
    static int search(const vi& arr, int target) {
        for (int i = 0; i < sz(arr); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    /**
     * @brief Find all occurrences of a target value
     * @param arr Array to search in
     * @param target Value to search for
     * @return Vector of indices where target is found
     */
    static vi findAll(const vi& arr, int target) {
        vi result;
        for (int i = 0; i < sz(arr); i++) {
            if (arr[i] == target) {
                result.pb(i);
            }
        }
        return result;
    }
    
    /**
     * @brief Find first occurrence of a target value
     * @param arr Array to search in
     * @param target Value to search for
     * @return Index of first occurrence, -1 if not found
     */
    static int findFirst(const vi& arr, int target) {
        for (int i = 0; i < sz(arr); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    /**
     * @brief Find last occurrence of a target value
     * @param arr Array to search in
     * @param target Value to search for
     * @return Index of last occurrence, -1 if not found
     */
    static int findLast(const vi& arr, int target) {
        for (int i = sz(arr) - 1; i >= 0; i--) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    /**
     * @brief Search in 2D array
     * @param matrix 2D array to search in
     * @param target Value to search for
     * @return Pair of (row, col) if found, (-1, -1) otherwise
     */
    static pii search2D(const vector<vi>& matrix, int target) {
        for (int i = 0; i < sz(matrix); i++) {
            for (int j = 0; j < sz(matrix[i]); j++) {
                if (matrix[i][j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    
    /**
     * @brief Find maximum element
     * @param arr Array to search in
     * @return Index of maximum element
     */
    static int findMax(const vi& arr) {
        if (arr.empty()) return -1;
        
        int maxIdx = 0;
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    
    /**
     * @brief Find minimum element
     * @param arr Array to search in
     * @return Index of minimum element
     */
    static int findMin(const vi& arr) {
        if (arr.empty()) return -1;
        
        int minIdx = 0;
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
        }
        return minIdx;
    }
    
    /**
     * @brief Find element using custom predicate
     * @param arr Array to search in
     * @param predicate Function that returns true for desired element
     * @return Index of first element satisfying predicate, -1 if not found
     */
    static int findIf(const vi& arr, function<bool(int)> predicate) {
        for (int i = 0; i < sz(arr); i++) {
            if (predicate(arr[i])) {
                return i;
            }
        }
        return -1;
    }
};

#endif // LINEAR_SEARCH_HPP
