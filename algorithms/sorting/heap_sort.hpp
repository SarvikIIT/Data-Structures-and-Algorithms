/**
 * @file heap_sort.hpp
 * @brief Heap Sort Algorithm Implementation
 * 
 * This header provides a comprehensive implementation of the Heap Sort algorithm
 * with various optimizations and utility functions.
 * 
 * Features:
 * - Standard Heap Sort
 * - Min-heap and Max-heap sorting
 * - In-place sorting
 * - Custom comparator support
 * - Heap operations (build, extract, insert)
 * - Priority queue implementation
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "utilities/common.hpp"

class HeapSort {
public:
    /**
     * @brief Standard heap sort (max-heap)
     * @param arr Array to sort
     */
    static void sort(vi& arr) {
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
     * @brief Min-heap sort (descending order)
     * @param arr Array to sort
     */
    static void sortMinHeap(vi& arr) {
        int n = sz(arr);
        
        // Build min heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
        
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            minHeapify(arr, i, 0);
        }
    }
    
    /**
     * @brief Sort with custom comparator
     * @param arr Array to sort
     * @param comp Comparator function
     */
    template<typename Compare>
    static void sortWithComparator(vi& arr, Compare comp) {
        int n = sz(arr);
        
        // Build heap with custom comparator
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyWithComparator(arr, n, i, comp);
        }
        
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyWithComparator(arr, i, 0, comp);
        }
    }
    
    /**
     * @brief Build max heap from array
     * @param arr Array to heapify
     * @param n Size of heap
     * @param i Index to heapify from
     */
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
    
    /**
     * @brief Build min heap from array
     * @param arr Array to heapify
     * @param n Size of heap
     * @param i Index to heapify from
     */
    static void minHeapify(vi& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        
        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }
    
    /**
     * @brief Insert element into heap
     * @param arr Heap array
     * @param n Current size
     * @param key Value to insert
     */
    static void insert(vi& arr, int& n, int key) {
        n++;
        int i = n - 1;
        arr.pb(key);
        
        // Fix heap property
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    
    /**
     * @brief Extract maximum element from heap
     * @param arr Heap array
     * @param n Current size
     * @return Maximum element
     */
    static int extractMax(vi& arr, int& n) {
        if (n <= 0) return -1;
        if (n == 1) {
            n--;
            return arr[0];
        }
        
        int root = arr[0];
        arr[0] = arr[n - 1];
        n--;
        arr.pop_back();
        
        heapify(arr, n, 0);
        return root;
    }
    
    /**
     * @brief Check if array is a valid max heap
     * @param arr Array to check
     * @return true if valid max heap
     */
    static bool isMaxHeap(const vi& arr) {
        int n = sz(arr);
        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }
    
    /**
     * @brief Check if array is a valid min heap
     * @param arr Array to check
     * @return true if valid min heap
     */
    static bool isMinHeap(const vi& arr) {
        int n = sz(arr);
        for (int i = 0; i < n; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n && arr[i] > arr[left]) return false;
            if (right < n && arr[i] > arr[right]) return false;
        }
        return true;
    }
    
    /**
     * @brief Get kth largest element using heap
     * @param arr Array to search in
     * @param k Position (1-indexed)
     * @return kth largest element
     */
    static int findKthLargest(vi arr, int k) {
        int n = sz(arr);
        
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        // Extract k-1 elements
        for (int i = 0; i < k - 1; i++) {
            swap(arr[0], arr[n - 1]);
            n--;
            heapify(arr, n, 0);
        }
        
        return arr[0];
    }
    
    /**
     * @brief Get kth smallest element using heap
     * @param arr Array to search in
     * @param k Position (1-indexed)
     * @return kth smallest element
     */
    static int findKthSmallest(vi arr, int k) {
        int n = sz(arr);
        
        // Build min heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
        
        // Extract k-1 elements
        for (int i = 0; i < k - 1; i++) {
            swap(arr[0], arr[n - 1]);
            n--;
            minHeapify(arr, n, 0);
        }
        
        return arr[0];
    }
    
private:
    /**
     * @brief Heapify with custom comparator
     * @param arr Array to heapify
     * @param n Size of heap
     * @param i Index to heapify from
     * @param comp Comparator function
     */
    template<typename Compare>
    static void heapifyWithComparator(vi& arr, int n, int i, Compare comp) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && comp(arr[left], arr[largest])) {
            largest = left;
        }
        
        if (right < n && comp(arr[right], arr[largest])) {
            largest = right;
        }
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyWithComparator(arr, n, largest, comp);
        }
    }
};

#endif // HEAP_SORT_HPP
