# Data Structures and Algorithmic Work

A comprehensive C++ library of data structures and algorithms optimized for competitive programming and software development. This repository showcases advanced implementations with detailed documentation and professional code organization.

## 🚀 Features

- **Professional Documentation**: Every header file includes comprehensive documentation with time/space complexity analysis
- **Competitive Programming Optimized**: All implementations are designed for maximum performance in contests
- **Modular Design**: Clean separation of concerns with reusable components
- **Multiple Approaches**: Various implementations for the same problem (memoization, tabulation, space-optimized)
- **Production Ready**: Well-tested code with proper error handling and edge case coverage

## 📁 Repository Structure

```
ds-algo-header-files/
├── data_structures/          # Core data structure implementations
│   ├── segment_tree.h        # Segment Tree with Lazy Propagation
│   ├── dsu.h                # Disjoint Set Union (Union-Find)
│   └── binary_search_tree.h # Binary Search Tree implementation
├── algorithms/               # Algorithm implementations
│   ├── graph_algorithms.h   # Graph algorithms (Dijkstra, BFS, DFS, etc.)
│   ├── binary_search.h      # Binary search variants
│   └── sorting.h            # Sorting algorithms
├── utilities/               # Utility functions and common definitions
│   ├── common.h             # Common types and macros
│   ├── math_utils.h         # Mathematical utilities
│   └── hash_utils.h         # Hash functions and safe containers
├── dp_problems/             # Dynamic Programming problem solutions
│   ├── fibonacci.cpp        # Fibonacci sequence implementations
│   ├── longest_increasing_subsequence.cpp
│   └── coin_change.cpp      # Coin change problem variants
├── examples/                # Usage examples and test cases
└── README.md               # This file
```

## 🛠️ Data Structures

### Segment Tree
- **File**: `data_structures/segment_tree.h`
- **Features**: Range queries, point updates, range updates with lazy propagation
- **Time Complexity**: O(log n) for queries and updates
- **Use Cases**: Range minimum/maximum queries, range sum queries

### Disjoint Set Union (DSU)
- **File**: `data_structures/dsu.h`
- **Features**: Path compression, union by rank, set size tracking
- **Time Complexity**: O(α(n)) amortized (practically constant)
- **Use Cases**: Connected components, minimum spanning tree (Kruskal's)

### Binary Search Tree
- **File**: `data_structures/binary_search_tree.h`
- **Features**: Insertion, deletion, search, traversal
- **Time Complexity**: O(log n) average, O(n) worst case
- **Use Cases**: Dynamic sorted data, range queries

## 🔧 Algorithms

### Graph Algorithms
- **File**: `algorithms/graph_algorithms.h`
- **Features**:
  - Dijkstra's Algorithm (shortest path)
  - Bellman-Ford Algorithm (negative weights)
  - Kruskal's Algorithm (MST)
  - BFS/DFS traversal
  - Topological sort
  - Cycle detection

### Binary Search
- **File**: `algorithms/binary_search.h`
- **Features**:
  - Standard binary search
  - Lower/upper bound
  - Binary search on answer
  - Real number binary search
  - Custom predicate search

### Sorting Algorithms
- **File**: `algorithms/sorting.h`
- **Features**:
  - Quick Sort
  - Merge Sort
  - Heap Sort
  - Counting Sort
  - Radix Sort
  - Custom comparator sorting

## 🧮 Dynamic Programming

### Fibonacci Sequence
- **File**: `dp_problems/fibonacci.cpp`
- **Approaches**:
  - Memoization (O(n))
  - Tabulation (O(n))
  - Space-optimized (O(1) space)
  - Matrix exponentiation (O(log n))

### Longest Increasing Subsequence
- **File**: `dp_problems/longest_increasing_subsequence.cpp`
- **Approaches**:
  - Memoization (O(n²))
  - Tabulation (O(n²))
  - Binary search (O(n log n))
  - Sequence reconstruction

### Coin Change Problem
- **File**: `dp_problems/coin_change.cpp`
- **Variants**:
  - Minimum coins needed
  - Count of ways to make change
  - Solution reconstruction
  - Space-optimized solutions

## 🚀 Quick Start

### Basic Usage

```cpp
#include "utilities/common.h"
#include "data_structures/segment_tree.h"
#include "algorithms/graph_algorithms.h"

int main() {
    // Example: Using Segment Tree
    vi arr = {1, 3, 2, 4, 5};
    SegmentTree st(arr);
    
    cout << "Range minimum [1, 3]: " << st.rangeMin(1, 3) << endl;
    
    // Example: Using Graph Algorithms
    vector<vpii> graph = {{{1, 4}, {2, 1}}, {{2, 2}, {3, 5}}, {{3, 1}}, {}};
    vi distances = GraphAlgorithms::dijkstra(graph, 0);
    
    for (int i = 0; i < sz(distances); i++) {
        cout << "Distance to " << i << ": " << distances[i] << endl;
    }
    
    return 0;
}
```

### Compilation

```bash
g++ -std=c++17 -O2 -o solution solution.cpp
```

## 📊 Performance Characteristics

| Data Structure | Operation | Time Complexity | Space Complexity |
|----------------|-----------|-----------------|------------------|
| Segment Tree | Query/Update | O(log n) | O(n) |
| DSU | Find/Union | O(α(n)) | O(n) |
| BST | Insert/Search/Delete | O(log n) avg | O(n) |
| Dijkstra | Shortest Path | O((V+E) log V) | O(V+E) |
| Binary Search | Search | O(log n) | O(1) |

## 🎯 Competitive Programming Tips

1. **Always include the utilities**: Start with `#include "utilities/common.h"`
2. **Use fast I/O**: The library includes optimized input/output functions
3. **Modular approach**: Include only what you need to reduce compilation time
4. **Memory management**: All implementations are memory-efficient
5. **Edge cases**: All functions handle edge cases properly

## 🔍 Testing

Each implementation includes comprehensive test cases and examples. Run the DP problem files to see various approaches in action:

```bash
g++ -std=c++17 -O2 fibonacci.cpp -o fibonacci
./fibonacci
```

## 📈 Future Enhancements

- [ ] Advanced data structures (Fenwick Tree, Sparse Table)
- [ ] String algorithms (KMP, Z-algorithm, Suffix Array)
- [ ] Number theory algorithms
- [ ] Geometry algorithms
- [ ] More DP patterns and optimizations
- [ ] Unit tests and benchmarks

## 🤝 Contributing

This library is designed to showcase algorithmic skills and serve as a reference for competitive programming. Feel free to:

- Report bugs or issues
- Suggest new algorithms or optimizations
- Improve documentation
- Add more test cases

## 📝 License

This project is open source and available under the MIT License.

## 🏆 Skills Demonstrated

- **Advanced C++ Programming**: Modern C++ features, templates, STL usage
- **Algorithm Design**: Efficient implementations with optimal time/space complexity
- **Data Structure Mastery**: Complex data structures with proper abstractions
- **Competitive Programming**: Contest-optimized code with fast I/O and memory management
- **Software Engineering**: Clean code, documentation, modular design
- **Problem Solving**: Multiple approaches to the same problem, edge case handling

---

*This repository represents a comprehensive collection of data structures and algorithms, showcasing proficiency in competitive programming and software development.*
