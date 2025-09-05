/**
 * @file bubble_sort.hpp
 * @brief Bubble Sort Algorithm
 * 
 * This header provides implementations for bubble sort
 * with various optimizations and variations.
 * 
 * Features:
 * - Standard bubble sort
 * - Optimized bubble sort
 * - Cocktail sort (bidirectional)
 * - Flagged bubble sort
 * - Custom comparator support
 * 
 * Time Complexity: O(n²) worst case, O(n) best case
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "utilities/common.hpp"

class BubbleSort {
public:
    /**
     * @brief Standard bubble sort
     * @param arr Array to sort
     */
    static void sort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    /**
     * @brief Optimized bubble sort (stops if no swaps)
     * @param arr Array to sort
     */
    static void optimizedSort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    
    /**
     * @brief Cocktail sort (bidirectional bubble sort)
     * @param arr Array to sort
     */
    static void cocktailSort(vector<int>& arr) {
        int n = sz(arr);
        int start = 0, end = n - 1;
        bool swapped = true;
        
        while (swapped) {
            swapped = false;
            
            // Forward pass
            for (int i = start; i < end; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
            
            if (!swapped) break;
            
            end--;
            
            // Backward pass
            for (int i = end; i > start; i--) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                    swapped = true;
                }
            }
            
            start++;
        }
    }
    
    /**
     * @brief Bubble sort with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     */
    static void sortCustom(vector<int>& arr, bool (*comp)(int, int)) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (comp(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    /**
     * @brief Optimized bubble sort with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     */
    static void optimizedSortCustom(vector<int>& arr, bool (*comp)(int, int)) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (comp(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    
    /**
     * @brief Count number of swaps in bubble sort
     * @param arr Array to sort
     * @return Number of swaps performed
     */
    static int countSwaps(vector<int>& arr) {
        int n = sz(arr);
        int swaps = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
        
        return swaps;
    }
    
    /**
     * @brief Check if array is sorted
     * @param arr Array to check
     * @return true if sorted
     */
    static bool isSorted(const vector<int>& arr) {
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Check if array is sorted with custom comparator
     * @param arr Array to check
     * @param comp Comparator function
     * @return true if sorted
     */
    static bool isSortedCustom(const vector<int>& arr, bool (*comp)(int, int)) {
        for (int i = 1; i < sz(arr); i++) {
            if (comp(arr[i], arr[i - 1])) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Sort array and return sorted copy
     * @param arr Original array
     * @return Sorted copy
     */
    static vector<int> sortCopy(const vector<int>& arr) {
        vector<int> result = arr;
        sort(result);
        return result;
    }
    
    /**
     * @brief Sort array in descending order
     * @param arr Array to sort
     */
    static void sortDescending(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    /**
     * @brief Sort array and count inversions
     * @param arr Array to sort
     * @return Number of inversions
     */
    static long long countInversions(vector<int>& arr) {
        int n = sz(arr);
        long long inversions = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    inversions++;
                }
            }
        }
        
        return inversions;
    }
};

#endif // BUBBLE_SORT_HPP
