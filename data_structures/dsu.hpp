/**
 * @file dsu.h
 * @brief Disjoint Set Union (DSU) / Union-Find Data Structure
 * 
 * This header provides an efficient implementation of the Disjoint Set Union data structure
 * with path compression and union by rank optimizations. It supports:
 * - Finding the root of a set (with path compression)
 * - Unioning two sets (with union by rank)
 * - Checking if two elements are in the same set
 * - Getting the size of a set
 * 
 * Time Complexity:
 * - find(): O(α(n)) amortized (α is inverse Ackermann function, practically constant)
 * - unite(): O(α(n)) amortized
 * - same(): O(α(n)) amortized
 * - getSize(): O(α(n)) amortized
 * 
 * Space Complexity: O(n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef DSU_H
#define DSU_H

#include "utilities/common.hpp"

class DSU {
private:
    vi parent, rank, size;
    
public:
    /**
     * @brief Constructor to initialize DSU with n elements
     * @param n Number of elements (0 to n-1)
     */
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        rep(i, 0, n) parent[i] = i;
    }
    
    /**
     * @brief Find the root of the set containing element x
     * Uses path compression for optimization
     * @param x Element to find root for
     * @return Root of the set containing x
     */
    inline int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    /**
     * @brief Union two sets containing elements x and y
     * Uses union by rank for optimization
     * @param x First element
     * @param y Second element
     */
    inline void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[py] = px;
            rank[px]++;
            size[px] += size[py];
        }
    }
    
    /**
     * @brief Check if two elements are in the same set
     * @param x First element
     * @param y Second element
     * @return true if x and y are in the same set, false otherwise
     */
    inline bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    /**
     * @brief Get the size of the set containing element x
     * @param x Element to get set size for
     * @return Size of the set containing x
     */
    inline int getSize(int x) {
        return size[find(x)];
    }
};

#endif // DSU_H
