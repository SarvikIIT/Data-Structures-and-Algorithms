/**
 * @file quick_sort.hpp
 * @brief Quick Sort Algorithm Implementation
 * 
 * This header provides a comprehensive implementation of the Quick Sort algorithm
 * with various optimizations and utility functions.
 * 
 * Features:
 * - Standard Quick Sort
 * - Randomized Quick Sort
 * - 3-way Quick Sort (for duplicate elements)
 * - Quick Select (find kth element)
 * - Custom comparator support
 * 
 * Time Complexity:
 * - Average: O(n log n)
 * - Worst: O(n²)
 * - Best: O(n log n)
 * 
 * Space Complexity: O(log n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "utilities/common.hpp"

class QuickSort {
public:
    /**
     * @brief Standard Quick Sort
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void sort(vi& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            sort(arr, left, pivotIndex - 1);
            sort(arr, pivotIndex + 1, right);
        }
    }
    
    /**
     * @brief Randomized Quick Sort
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void randomizedSort(vi& arr, int left, int right) {
        if (left < right) {
            int randomIndex = left + rand() % (right - left + 1);
            swap(arr[randomIndex], arr[right]);
            
            int pivotIndex = partition(arr, left, right);
            randomizedSort(arr, left, pivotIndex - 1);
            randomizedSort(arr, pivotIndex + 1, right);
        }
    }
    
    /**
     * @brief 3-way Quick Sort for arrays with many duplicates
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void threeWaySort(vi& arr, int left, int right) {
        if (left >= right) return;
        
        int pivot = arr[left];
        int lt = left;      // arr[left+1..lt] < pivot
        int i = left + 1;   // arr[lt+1..i-1] == pivot
        int gt = right;     // arr[gt..right] > pivot
        
        while (i <= gt) {
            if (arr[i] < pivot) {
                swap(arr[lt++], arr[i++]);
            } else if (arr[i] > pivot) {
                swap(arr[i], arr[gt--]);
            } else {
                i++;
            }
        }
        
        threeWaySort(arr, left, lt - 1);
        threeWaySort(arr, gt + 1, right);
    }
    
    /**
     * @brief Quick Select - find kth smallest element
     * @param arr Array to search in
     * @param left Starting index
     * @param right Ending index
     * @param k Position (1-indexed)
     * @return kth smallest element
     */
    static int quickSelect(vi& arr, int left, int right, int k) {
        if (left == right) return arr[left];
        
        int pivotIndex = partition(arr, left, right);
        int leftLength = pivotIndex - left + 1;
        
        if (k == leftLength) {
            return arr[pivotIndex];
        } else if (k < leftLength) {
            return quickSelect(arr, left, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k - leftLength);
        }
    }
    
    /**
     * @brief Sort with custom comparator
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     * @param comp Comparator function
     */
    template<typename Compare>
    static void sortWithComparator(vi& arr, int left, int right, Compare comp) {
        if (left < right) {
            int pivotIndex = partitionWithComparator(arr, left, right, comp);
            sortWithComparator(arr, left, pivotIndex - 1, comp);
            sortWithComparator(arr, pivotIndex + 1, right, comp);
        }
    }
    
    /**
     * @brief Check if array is sorted
     * @param arr Array to check
     * @return true if sorted, false otherwise
     */
    static bool isSorted(const vi& arr) {
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
private:
    /**
     * @brief Partition function for Quick Sort
     * @param arr Array to partition
     * @param left Starting index
     * @param right Ending index
     * @return Final position of pivot
     */
    static int partition(vi& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }
    
    /**
     * @brief Partition function with custom comparator
     * @param arr Array to partition
     * @param left Starting index
     * @param right Ending index
     * @param comp Comparator function
     * @return Final position of pivot
     */
    template<typename Compare>
    static int partitionWithComparator(vi& arr, int left, int right, Compare comp) {
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (comp(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }
};

#endif // QUICK_SORT_HPP
