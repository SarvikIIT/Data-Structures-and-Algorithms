/**
 * @file sorting.h
 * @brief Sorting Algorithms Implementation
 * 
 * This header provides comprehensive implementations of sorting algorithms
 * commonly used in competitive programming. It includes:
 * - Quick Sort (in-place)
 * - Merge Sort (stable)
 * - Heap Sort
 * - Counting Sort (for small range integers)
 * - Radix Sort (for integers)
 * - Custom comparator sorting utilities
 * 
 * All algorithms are optimized for competitive programming with proper
 * handling of edge cases and performance considerations.
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef SORTING_H
#define SORTING_H

#include "utilities/common.hpp"

class Sorting {
public:
    /**
     * @brief Quick Sort implementation
     * @param arr Array to sort
     * @param low Starting index
     * @param high Ending index
     * 
     * Time Complexity: O(n log n) average, O(n²) worst case
     * Space Complexity: O(log n)
     */
    static void quickSort(vi& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
    
    /**
     * @brief Merge Sort implementation
     * @param arr Array to sort
     * @param left Starting index
     * @param right Ending index
     * 
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */
    static void mergeSort(vi& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    /**
     * @brief Heap Sort implementation
     * @param arr Array to sort
     * 
     * Time Complexity: O(n log n)
     * Space Complexity: O(1)
     */
    static void heapSort(vi& arr) {
        int n = sz(arr);
        
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    
    /**
     * @brief Counting Sort for small range integers
     * @param arr Array to sort
     * @param maxVal Maximum value in array
     * 
     * Time Complexity: O(n + k) where k is the range
     * Space Complexity: O(k)
     */
    static void countingSort(vi& arr, int maxVal) {
        int n = sz(arr);
        vi count(maxVal + 1, 0);
        vi output(n);
        
        // Count occurrences
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        
        // Modify count array to store actual position
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i - 1];
        }
        
        // Build output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        
        // Copy output back to original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
    
    /**
     * @brief Radix Sort for integers
     * @param arr Array to sort
     * 
     * Time Complexity: O(d * (n + k)) where d is number of digits, k is base
     * Space Complexity: O(n + k)
     */
    static void radixSort(vi& arr) {
        int maxVal = *max_element(all(arr));
        
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            countingSortByDigit(arr, exp);
        }
    }
    
    /**
     * @brief Sort array with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     * 
     * Time Complexity: O(n log n)
     * Space Complexity: O(1)
     */
    template<typename T, typename Compare>
    static void customSort(vector<T>& arr, Compare comp) {
        sort(all(arr), comp);
    }
    
    /**
     * @brief Check if array is sorted
     * @param arr Array to check
     * @return true if sorted, false otherwise
     * 
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    static bool isSorted(const vi& arr) {
        for (int i = 1; i < sz(arr); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Find kth largest element using quick select
     * @param arr Array to search in
     * @param k Position (1-indexed)
     * @return kth largest element
     * 
     * Time Complexity: O(n) average, O(n²) worst case
     * Space Complexity: O(1)
     */
    static int quickSelect(vi& arr, int k) {
        int left = 0, right = sz(arr) - 1;
        
        while (left <= right) {
            int pivotIndex = partition(arr, left, right);
            
            if (pivotIndex == k - 1) {
                return arr[pivotIndex];
            } else if (pivotIndex < k - 1) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        return -1; // Should not reach here
    }
    
private:
    static int partition(vi& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
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
    
    static void heapify(vi& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    static void countingSortByDigit(vi& arr, int exp) {
        int n = sz(arr);
        vi count(10, 0);
        vi output(n);
        
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
};

#endif // SORTING_H
