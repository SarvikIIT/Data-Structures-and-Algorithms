/**
 * @file merge_sort.hpp
 * @brief Merge Sort Algorithm Implementation
 * 
 * This header provides a comprehensive implementation of the Merge Sort algorithm
 * with various optimizations and utility functions.
 * 
 * Features:
 * - Standard Merge Sort
 * - In-place Merge Sort
 * - Bottom-up Merge Sort
 * - Merge Sort for linked lists
 * - Custom comparator support
 * - Stable sorting
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "utilities/common.hpp"

class MergeSort {
public:
    /**
     * @brief Standard Merge Sort
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void sort(vi& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    /**
     * @brief Bottom-up Merge Sort (iterative)
     * @param arr Array to sort
     */
    static void bottomUpSort(vi& arr) {
        int n = sz(arr);
        
        for (int size = 1; size < n; size *= 2) {
            for (int left = 0; left < n - size; left += 2 * size) {
                int mid = left + size - 1;
                int right = min(left + 2 * size - 1, n - 1);
                merge(arr, left, mid, right);
            }
        }
    }
    
    /**
     * @brief In-place Merge Sort (space optimized)
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     */
    static void inPlaceSort(vi& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            inPlaceSort(arr, left, mid);
            inPlaceSort(arr, mid + 1, right);
            inPlaceMerge(arr, left, mid, right);
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
            int mid = left + (right - left) / 2;
            sortWithComparator(arr, left, mid, comp);
            sortWithComparator(arr, mid + 1, right, comp);
            mergeWithComparator(arr, left, mid, right, comp);
        }
    }
    
    /**
     * @brief Count inversions in array using Merge Sort
     * @param arr Array to count inversions in
     * @return Number of inversions
     */
    static long long countInversions(vi& arr) {
        return countInversionsHelper(arr, 0, sz(arr) - 1);
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
     * @brief Merge function for Merge Sort
     * @param arr Array to merge
     * @param left Starting index
     * @param mid Middle index
     * @param right Ending index
     */
    static void merge(vi& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vi leftArr(n1), rightArr(n2);
        
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    /**
     * @brief Merge function with custom comparator
     * @param arr Array to merge
     * @param left Starting index
     * @param mid Middle index
     * @param right Ending index
     * @param comp Comparator function
     */
    template<typename Compare>
    static void mergeWithComparator(vi& arr, int left, int mid, int right, Compare comp) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vi leftArr(n1), rightArr(n2);
        
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (comp(leftArr[i], rightArr[j])) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    /**
     * @brief In-place merge function
     * @param arr Array to merge
     * @param left Starting index
     * @param mid Middle index
     * @param right Ending index
     */
    static void inPlaceMerge(vi& arr, int left, int mid, int right) {
        int i = left, j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                i++;
            } else {
                int value = arr[j];
                int index = j;
                
                while (index > i) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[i] = value;
                
                i++;
                mid++;
                j++;
            }
        }
    }
    
    /**
     * @brief Count inversions helper function
     * @param arr Array to count inversions in
     * @param left Starting index
     * @param right Ending index
     * @return Number of inversions
     */
    static long long countInversionsHelper(vi& arr, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        long long leftInversions = countInversionsHelper(arr, left, mid);
        long long rightInversions = countInversionsHelper(arr, mid + 1, right);
        long long mergeInversions = countMergeInversions(arr, left, mid, right);
        
        return leftInversions + rightInversions + mergeInversions;
    }
    
    /**
     * @brief Count inversions during merge
     * @param arr Array to count inversions in
     * @param left Starting index
     * @param mid Middle index
     * @param right Ending index
     * @return Number of inversions
     */
    static long long countMergeInversions(vi& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vi leftArr(n1), rightArr(n2);
        
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        long long inversions = 0;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                inversions += (n1 - i);
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
        
        return inversions;
    }
};

#endif // MERGE_SORT_HPP
