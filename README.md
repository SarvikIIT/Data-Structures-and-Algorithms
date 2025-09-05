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
│   ├── segment_tree.hpp      # Segment Tree with Lazy Propagation
│   ├── dsu.hpp              # Disjoint Set Union (Union-Find)
│   └── binary_search_tree.hpp # Binary Search Tree implementation
├── algorithms/               # Algorithm implementations
│   ├── graph/               # Graph algorithms
│   │   ├── dijkstra.hpp     # Dijkstra's shortest path
│   │   ├── bellman_ford.hpp # Bellman-Ford algorithm
│   │   ├── kruskal.hpp      # Kruskal's MST algorithm
│   │   └── bfs_dfs.hpp      # BFS, DFS, topological sort
│   ├── search/              # Search algorithms
│   │   ├── binary_search.hpp # Binary search variants
│   │   └── linear_search.hpp # Linear search algorithms
│   ├── sorting/             # Sorting algorithms
│   │   ├── quick_sort.hpp   # Quick sort implementation
│   │   └── merge_sort.hpp   # Merge sort implementation
│   └── math/                # Mathematical algorithms
│       ├── prime_sieve.hpp  # Prime sieve and number theory
│       ├── gcd_lcm.hpp      # GCD and LCM functions
│       ├── modular_arithmetic.hpp # Modular arithmetic operations
│       ├── combinatorics.hpp # Combinatorics functions (nCr)
│       ├── euler_totient.hpp # Euler's Totient function
│       ├── fibonacci.hpp    # Fibonacci sequence algorithms
│       ├── factorial.hpp    # Factorial precomputation
│       ├── binomial_coefficients.hpp # Binomial coefficient calculation
│       ├── is_prime.hpp     # Prime number checking algorithms
│       └── square_root.hpp  # Square root algorithms
├── utilities/               # Utility functions and common definitions
│   ├── common.hpp           # Common types and macros
│   ├── math_utils.hpp       # Mathematical utilities
│   └── hash_utils.hpp       # Hash functions and safe containers
├── dp_problems/             # Dynamic Programming problem solutions
│   ├── fibonacci.cpp        # Fibonacci sequence implementations
│   ├── longest_increasing_subsequence.cpp
│   └── coin_change.cpp      # Coin change problem variants
├── examples/                # Usage examples and test cases
│   └── basic_usage.cpp      # Comprehensive usage examples
├── LICENSE                  # MIT License
├── CONTRIBUTING.md          # Contribution guidelines
└── README.md               # This file
```

## 🛠️ Data Structures

### Segment Tree
- **File**: `data_structures/segment_tree.hpp`
- **Features**: Range queries, point updates, range updates with lazy propagation
- **Time Complexity**: O(log n) for queries and updates
- **Use Cases**: Range minimum/maximum queries, range sum queries

### Disjoint Set Union (DSU)
- **File**: `data_structures/dsu.hpp`
- **Features**: Path compression, union by rank, set size tracking
- **Time Complexity**: O(α(n)) amortized (practically constant)
- **Use Cases**: Connected components, minimum spanning tree (Kruskal's)

### Binary Search Tree
- **File**: `data_structures/binary_search_tree.hpp`
- **Features**: Insertion, deletion, search, traversal
- **Time Complexity**: O(log n) average, O(n) worst case
- **Use Cases**: Dynamic sorted data, range queries

## 🔧 Algorithms

### Graph Algorithms
- **Dijkstra's Algorithm** (`algorithms/graph/dijkstra.hpp`)
  - Single source shortest path
  - Non-negative edge weights
  - Path reconstruction
- **Bellman-Ford Algorithm** (`algorithms/graph/bellman_ford.hpp`)
  - Handles negative edge weights
  - Negative cycle detection
  - Path reconstruction
- **Kruskal's Algorithm** (`algorithms/graph/kruskal.hpp`)
  - Minimum spanning tree
  - Union-Find based
  - Connectivity checking
- **BFS/DFS** (`algorithms/graph/bfs_dfs.hpp`)
  - Graph traversal
  - Topological sort
  - Cycle detection
  - Connected components

### Search Algorithms
- **Binary Search** (`algorithms/search/binary_search.hpp`)
  - Standard binary search
  - Lower/upper bound
  - Binary search on answer
  - Real number binary search
  - Square root and nth root
- **Linear Search** (`algorithms/search/linear_search.hpp`)
  - Linear search variants
  - Find all occurrences
  - 2D array search
  - Custom predicate search

### Sorting Algorithms
- **Quick Sort** (`algorithms/sorting/quick_sort.hpp`)
  - Standard and randomized
  - 3-way partitioning
  - Quick select
  - Custom comparators
- **Merge Sort** (`algorithms/sorting/merge_sort.hpp`)
  - Stable sorting
  - Bottom-up implementation
  - In-place merge
  - Inversion counting

### Mathematical Algorithms
- **Prime Sieve** (`algorithms/math/prime_sieve.hpp`)
  - Sieve of Eratosthenes
  - Segmented sieve
  - Prime factorization
  - Number theory functions
- **GCD and LCM** (`algorithms/math/gcd_lcm.hpp`)
  - Euclidean algorithm
  - Extended Euclidean algorithm
  - LCM calculation
  - Binary GCD algorithm
- **Modular Arithmetic** (`algorithms/math/modular_arithmetic.hpp`)
  - Modular exponentiation
  - Modular inverse
  - Modular addition/multiplication
  - Chinese Remainder Theorem
- **Combinatorics** (`algorithms/math/combinatorics.hpp`)
  - nCr calculation
  - Factorial computation
  - Permutations and combinations
  - Pascal's triangle
- **Euler Totient** (`algorithms/math/euler_totient.hpp`)
  - Totient function calculation
  - Totient sieve
  - Totient properties
  - Euler's theorem applications
- **Fibonacci** (`algorithms/math/fibonacci.hpp`)
  - Matrix exponentiation
  - Fast doubling method
  - Fibonacci modulo
  - Lucas numbers
- **Factorial** (`algorithms/math/factorial.hpp`)
  - Factorial precomputation
  - Factorial modulo
  - Wilson's theorem
  - Factorial properties
- **Binomial Coefficients** (`algorithms/math/binomial_coefficients.hpp`)
  - Pascal's triangle
  - Lucas theorem
  - Multiplicative formula
  - Symmetry properties
- **Prime Checking** (`algorithms/math/is_prime.hpp`)
  - Basic prime checking
  - Fermat's test
  - Miller-Rabin test
  - AKS primality test
- **Square Root** (`algorithms/math/square_root.hpp`)
  - Binary search method
  - Newton's method
  - Babylonian method
  - Integer square root

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
#include "utilities/common.hpp"
#include "data_structures/segment_tree.hpp"
#include "algorithms/graph/dijkstra.hpp"

int main() {
    // Example: Using Segment Tree
    vi arr = {1, 3, 2, 4, 5};
    SegmentTree st(arr);
    
    cout << "Range minimum [1, 3]: " << st.rangeMin(1, 3) << endl;
    
    // Example: Using Graph Algorithms
    vector<vpii> graph = {{{1, 4}, {2, 1}}, {{2, 2}, {3, 5}}, {{3, 1}}, {}};
    vi distances = Dijkstra::shortestPath(graph, 0);
    
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

1. **Always include the utilities**: Start with `#include "utilities/common.hpp"`
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
