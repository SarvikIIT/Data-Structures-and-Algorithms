/**
 * @file basic_usage.cpp
 * @brief Basic usage examples for the DS-Algo library
 * 
 * This file demonstrates how to use various components of the library
 * in competitive programming scenarios.
 * 
 * @author Sarvik
 * @version 1.0
 */

#include "utilities/common.hpp"
#include "data_structures/segment_tree.hpp"
#include "data_structures/dsu.hpp"
#include "algorithms/graph/dijkstra.hpp"
#include "algorithms/graph/bfs_dfs.hpp"
#include "algorithms/search/binary_search.hpp"
#include "algorithms/sorting/quick_sort.hpp"
#include "algorithms/math/prime_sieve.hpp"

void segmentTreeExample() {
    cout << "=== Segment Tree Example ===" << endl;
    
    vi arr = {1, 3, 2, 4, 5, 6, 7, 8};
    SegmentTree st(arr);
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Range minimum [1, 4]: " << st.rangeMin(1, 4) << endl;
    cout << "Range minimum [0, 7]: " << st.rangeMin(0, 7) << endl;
    
    st.pointUpdate(2, 0);
    cout << "After updating index 2 to 0: " << st.rangeMin(1, 4) << endl;
    
    st.updateRange(1, 3, 2);
    cout << "After adding 2 to range [1, 3]: " << st.rangeMin(1, 4) << endl;
    cout << endl;
}

void dsuExample() {
    cout << "=== DSU Example ===" << endl;
    
    DSU dsu(5);
    
    cout << "Initial state:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Set " << i << " size: " << dsu.getSize(i) << endl;
    }
    
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(1, 2);
    
    cout << "\nAfter unions (0,1), (2,3), (1,2):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Set " << i << " size: " << dsu.getSize(i) << endl;
    }
    
    cout << "Are 0 and 3 in same set? " << (dsu.same(0, 3) ? "Yes" : "No") << endl;
    cout << "Are 0 and 4 in same set? " << (dsu.same(0, 4) ? "Yes" : "No") << endl;
    cout << endl;
}

void graphAlgorithmsExample() {
    cout << "=== Graph Algorithms Example ===" << endl;
    
    // Create a weighted graph
    vector<vpii> graph(4);
    graph[0] = {{1, 4}, {2, 1}};
    graph[1] = {{2, 2}, {3, 5}};
    graph[2] = {{3, 1}};
    graph[3] = {};
    
    cout << "Graph adjacency list:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << ": ";
        for (auto& edge : graph[i]) {
            cout << "(" << edge.ff << "," << edge.ss << ") ";
        }
        cout << endl;
    }
    
    vi distances = Dijkstra::shortestPath(graph, 0);
    cout << "\nShortest distances from node 0:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "To node " << i << ": " << distances[i] << endl;
    }
    cout << endl;
}

void binarySearchExample() {
    cout << "=== Binary Search Example ===" << endl;
    
    vi arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    int target = 7;
    int index = BinarySearch::search(arr, target);
    cout << "Search for " << target << ": " << (index != -1 ? "Found at index " + to_string(index) : "Not found") << endl;
    
    int lower = BinarySearch::lowerBound(arr, 6);
    int upper = BinarySearch::upperBound(arr, 6);
    cout << "Lower bound of 6: " << lower << " (value: " << arr[lower] << ")" << endl;
    cout << "Upper bound of 6: " << upper << " (value: " << (upper < sz(arr) ? to_string(arr[upper]) : "end") << ")" << endl;
    
    // Binary search on answer example
    int result = BinarySearch::binarySearchOnAnswer(0, 100, [](int x) {
        return x * x <= 50;
    });
    cout << "Largest x such that x² ≤ 50: " << result << endl;
    cout << endl;
}

void sortingExample() {
    cout << "=== Sorting Example ===" << endl;
    
    vi arr = {64, 34, 25, 12, 22, 11, 90, 5};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    vi quickArr = arr;
    QuickSort::sort(quickArr, 0, sz(quickArr) - 1);
    cout << "Quick sort: ";
    for (int x : quickArr) cout << x << " ";
    cout << endl;
    
    vi mergeArr = arr;
    MergeSort::sort(mergeArr, 0, sz(mergeArr) - 1);
    cout << "Merge sort: ";
    for (int x : mergeArr) cout << x << " ";
    cout << endl;
    
    // Custom sorting
    vi customArr = arr;
    QuickSort::sortWithComparator(customArr, 0, sz(customArr) - 1, [](int a, int b) {
        return a > b; // Sort in descending order
    });
    cout << "Custom sort (descending): ";
    for (int x : customArr) cout << x << " ";
    cout << endl;
    cout << endl;
}

void mathUtilsExample() {
    cout << "=== Math Utils Example ===" << endl;
    
    int a = 15, b = 25;
    cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << ": " << lcm(a, b) << endl;
    
    int n = 5, r = 2;
    precompute_factorials();
    cout << "C(" << n << "," << r << ") = " << nCr(n, r) << endl;
    
    int num = 42;
    cout << "Is " << num << " prime? " << (isPrime(num) ? "Yes" : "No") << endl;
    cout << "Binary representation of " << num << ": " << toBinary(num) << endl;
    cout << "Number of set bits in " << num << ": " << countBits(num) << endl;
    cout << endl;
}

void primeSieveExample() {
    cout << "=== Prime Sieve Example ===" << endl;
    
    PrimeSieve::initialize();
    
    cout << "First 10 primes: ";
    vi primes = PrimeSieve::getPrimes(30);
    for (int i = 0; i < min(10, sz(primes)); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
    
    int num = 60;
    cout << "Prime factorization of " << num << ": ";
    vector<pii> factors = PrimeSieve::primeFactorization(num);
    for (auto& factor : factors) {
        cout << factor.ff << "^" << factor.ss << " ";
    }
    cout << endl;
    
    cout << "Divisors of " << num << ": ";
    vi divisors = PrimeSieve::getDivisors(num);
    for (int div : divisors) {
        cout << div << " ";
    }
    cout << endl;
    
    cout << "Euler's totient of " << num << ": " << PrimeSieve::eulerTotient(num) << endl;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << "=== DS-Algo Library Usage Examples ===" << endl << endl;
    
    segmentTreeExample();
    dsuExample();
    graphAlgorithmsExample();
    binarySearchExample();
    sortingExample();
    mathUtilsExample();
    primeSieveExample();
    
    cout << "=== All examples completed successfully! ===" << endl;
    
    return 0;
}
