/**
 * @file insertion_sort.hpp
 * @brief Insertion Sort Algorithm
 * 
 * This header provides implementations for insertion sort
 * with various optimizations and variations.
 * 
 * Features:
 * - Standard insertion sort
 * - Binary insertion sort
 * - Shell sort (gap-based)
 * - Custom comparator support
 * - In-place sorting
 * 
 * Time Complexity: O(n²) worst case, O(n) best case
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "utilities/common.hpp"
#include "algorithms/search/binary_search.hpp"

class InsertionSort {
public:
    /**
     * @brief Standard insertion sort
     * @param arr Array to sort
     */
    static void sort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    /**
     * @brief Binary insertion sort (uses binary search)
     * @param arr Array to sort
     */
    static void binaryInsertionSort(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int pos = BinarySearch::lowerBound(arr, 0, i, key);
            
            for (int j = i; j > pos; j--) {
                arr[j] = arr[j - 1];
            }
            arr[pos] = key;
        }
    }
    
    /**
     * @brief Shell sort with gap sequence
     * @param arr Array to sort
     */
    static void shellSort(vector<int>& arr) {
        int n = sz(arr);
        
        // Start with a big gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Do a gapped insertion sort for this gap size
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
    
    /**
     * @brief Insertion sort with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     */
    static void sortCustom(vector<int>& arr, bool (*comp)(int, int)) {
        int n = sz(arr);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && comp(arr[j], key)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    /**
     * @brief Insert element in sorted position
     * @param arr Sorted array
     * @param element Element to insert
     */
    static void insertInSorted(vector<int>& arr, int element) {
        int n = sz(arr);
        arr.push_back(0); // Make space
        
        int i = n - 1;
        while (i >= 0 && arr[i] > element) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = element;
    }
    
    /**
     * @brief Insert element using binary search
     * @param arr Sorted array
     * @param element Element to insert
     */
    static void insertBinary(vector<int>& arr, int element) {
        int pos = BinarySearch::lowerBound(arr, 0, sz(arr), element);
        arr.insert(arr.begin() + pos, element);
    }
    
    /**
     * @brief Sort array in descending order
     * @param arr Array to sort
     */
    static void sortDescending(vector<int>& arr) {
        int n = sz(arr);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
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
     * @brief Count number of comparisons in insertion sort
     * @param arr Array to sort
     * @return Number of comparisons
     */
    static long long countComparisons(vector<int>& arr) {
        int n = sz(arr);
        long long comparisons = 0;
        
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                comparisons++;
                arr[j + 1] = arr[j];
                j--;
            }
            if (j >= 0) comparisons++;
            arr[j + 1] = key;
        }
        
        return comparisons;
    }
    
    /**
     * @brief Count number of shifts in insertion sort
     * @param arr Array to sort
     * @return Number of shifts
     */
    static long long countShifts(vector<int>& arr) {
        int n = sz(arr);
        long long shifts = 0;
        
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                shifts++;
            }
            arr[j + 1] = key;
        }
        
        return shifts;
    }
    
    /**
     * @brief Sort array with gap sequence
     * @param arr Array to sort
     * @param gaps Gap sequence
     */
    static void sortWithGaps(vector<int>& arr, const vector<int>& gaps) {
        int n = sz(arr);
        
        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
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

#endif // INSERTION_SORT_HPP
