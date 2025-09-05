/**
 * @file kruskal.hpp
 * @brief Kruskal's Algorithm for Minimum Spanning Tree
 * 
 * This header provides an implementation of Kruskal's algorithm for finding
 * the minimum spanning tree (MST) of a weighted undirected graph.
 * 
 * Features:
 * - Finds minimum spanning tree
 * - Uses Union-Find (DSU) for cycle detection
 * - Returns MST weight and edges
 * - Works with disconnected components
 * 
 * Time Complexity: O(E log E)
 * Space Complexity: O(V + E)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "utilities/common.hpp"
#include "data_structures/dsu.hpp"

class Kruskal {
public:
    /**
     * @brief Find minimum spanning tree
     * @param edges List of edges (weight, u, v)
     * @param n Number of vertices
     * @return Pair of (MST_weight, MST_edges)
     */
    static pair<int, vector<pii>> findMST(const vector<tuple<int, int, int>>& edges, int n) {
        DSU dsu(n);
        vector<tuple<int, int, int>> sortedEdges = edges;
        sort(all(sortedEdges));
        
        int mstWeight = 0;
        vector<pii> mstEdges;
        
        for (auto& edge : sortedEdges) {
            int w, u, v;
            tie(w, u, v) = edge;
            
            if (!dsu.same(u, v)) {
                dsu.unite(u, v);
                mstWeight += w;
                mstEdges.pb({u, v});
            }
        }
        
        return {mstWeight, mstEdges};
    }
    
    /**
     * @brief Check if MST exists (graph is connected)
     * @param edges List of edges (weight, u, v)
     * @param n Number of vertices
     * @return true if MST exists, false otherwise
     */
    static bool isConnected(const vector<tuple<int, int, int>>& edges, int n) {
        DSU dsu(n);
        
        for (auto& edge : edges) {
            int w, u, v;
            tie(w, u, v) = edge;
            dsu.unite(u, v);
        }
        
        // Check if all vertices are in the same component
        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) {
                return false;
            }
        }
        
        return true;
    }
};

#endif // KRUSKAL_HPP

