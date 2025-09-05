/**
 * @file bellman_ford.hpp
 * @brief Bellman-Ford Algorithm for Shortest Path with Negative Weights
 * 
 * This header provides an implementation of the Bellman-Ford algorithm for finding
 * the shortest path from a source vertex to all other vertices in a weighted graph
 * that may contain negative edge weights.
 * 
 * Features:
 * - Single source shortest path
 * - Handles negative edge weights
 * - Detects negative cycles
 * - Works with directed and undirected graphs
 * 
 * Time Complexity: O(VE)
 * Space Complexity: O(V)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

#include "utilities/common.hpp"

class BellmanFord {
public:
    /**
     * @brief Find shortest distances from source to all vertices
     * @param edges List of edges (u, v, weight)
     * @param n Number of vertices
     * @param source Starting vertex
     * @return Pair of (distances, has_negative_cycle)
     */
    static pair<vi, bool> shortestPath(const vector<tuple<int, int, int>>& edges, int n, int source) {
        vi dist(n, INF);
        dist[source] = 0;
        
        // Relax edges V-1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u, v, w;
                tie(u, v, w) = edge;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Check for negative cycles
        bool hasNegativeCycle = false;
        for (auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                hasNegativeCycle = true;
                break;
            }
        }
        
        return {dist, hasNegativeCycle};
    }
    
    /**
     * @brief Find shortest path from source to target
     * @param edges List of edges (u, v, weight)
     * @param n Number of vertices
     * @param source Starting vertex
     * @param target Destination vertex
     * @return Pair of (shortest distance, path as vector of vertices)
     */
    static pair<int, vi> shortestPathToTarget(const vector<tuple<int, int, int>>& edges, int n, int source, int target) {
        vi dist(n, INF);
        vi parent(n, -1);
        dist[source] = 0;
        
        // Relax edges V-1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u, v, w;
                tie(u, v, w) = edge;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
        
        // Check for negative cycles
        for (auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return {-1, {}}; // Negative cycle detected
            }
        }
        
        if (dist[target] == INF) {
            return {-1, {}};
        }
        
        // Reconstruct path
        vi path;
        int curr = target;
        while (curr != -1) {
            path.pb(curr);
            curr = parent[curr];
        }
        reverse(all(path));
        
        return {dist[target], path};
    }
};

#endif // BELLMAN_FORD_HPP
