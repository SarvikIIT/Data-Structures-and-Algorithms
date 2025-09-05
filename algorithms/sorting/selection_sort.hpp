/**
 * @file selection_sort.hpp
 * @brief Selection Sort Algorithm
 * 
 * This header provides implementations for selection sort
 * with various optimizations and variations.
 * 
 * Features:
 * - Standard selection sort
 * - Stable selection sort
 * - Custom comparator support
 * - In-place sorting
 * - Performance analysis
 * 
 * Time Complexity: O(n²) in all cases
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "utilities/common.hpp"

class SelectionSort {
public:
    /**
     * @brief Standard selection sort
     * @param arr Array to sort
     */
    static void sort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }
    
    /**
     * @brief Selection sort with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     */
    static void sortCustom(vector<int>& arr, bool (*comp)(int, int)) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (comp(arr[j], arr[minIdx])) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }
    
    /**
     * @brief Stable selection sort
     * @param arr Array to sort
     */
    static void stableSort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                // Shift elements to maintain stability
                int key = arr[minIdx];
                for (int k = minIdx; k > i; k--) {
                    arr[k] = arr[k - 1];
                }
                arr[i] = key;
            }
        }
    }
    
    /**
     * @brief Sort array in descending order
     * @param arr Array to sort
     */
    static void sortDescending(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 0; i < n - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[maxIdx]) {
                    maxIdx = j;
                }
            }
            if (maxIdx != i) {
                swap(arr[i], arr[maxIdx]);
            }
        }
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
     * @brief Count number of comparisons in selection sort
     * @param arr Array to sort
     * @return Number of comparisons
     */
    static long long countComparisons(vector<int>& arr) {
        int n = sz(arr);
        long long comparisons = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
        
        return comparisons;
    }
    
    /**
     * @brief Count number of swaps in selection sort
     * @param arr Array to sort
     * @return Number of swaps
     */
    static long long countSwaps(vector<int>& arr) {
        int n = sz(arr);
        long long swaps = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
                swaps++;
            }
        }
        
        return swaps;
    }
    
    /**
     * @brief Find minimum element in range
     * @param arr Array
     * @param start Start index
     * @param end End index
     * @return Index of minimum element
     */
    static int findMinIndex(const vector<int>& arr, int start, int end) {
        int minIdx = start;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
        }
        return minIdx;
    }
    
    /**
     * @brief Find maximum element in range
     * @param arr Array
     * @param start Start index
     * @param end End index
     * @return Index of maximum element
     */
    static int findMaxIndex(const vector<int>& arr, int start, int end) {
        int maxIdx = start;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    
    /**
     * @brief Sort array and find kth smallest element
     * @param arr Array to sort
     * @param k Position (1-indexed)
     * @return Kth smallest element
     */
    static int findKthSmallest(vector<int>& arr, int k) {
        if (k < 1 || k > sz(arr)) return -1;
        
        sort(arr);
        return arr[k - 1];
    }
    
    /**
     * @brief Sort array and find kth largest element
     * @param arr Array to sort
     * @param k Position (1-indexed)
     * @return Kth largest element
     */
    static int findKthLargest(vector<int>& arr, int k) {
        if (k < 1 || k > sz(arr)) return -1;
        
        sortDescending(arr);
        return arr[k - 1];
    }
    
    /**
     * @brief Partial selection sort (sort first k elements)
     * @param arr Array to sort
     * @param k Number of elements to sort
     */
    static void partialSort(vector<int>& arr, int k) {
        int n = sz(arr);
        k = min(k, n);
        
        for (int i = 0; i < k; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }
    
    /**
     * @brief Sort array and find median
     * @param arr Array to sort
     * @return Median value
     */
    static double findMedian(vector<int>& arr) {
        sort(arr);
        int n = sz(arr);
        
        if (n % 2 == 0) {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        } else {
            return arr[n / 2];
        }
    }
};

#endif // SELECTION_SORT_HPP
