/**
 * @file graph_algorithms.h
 * @brief Graph Algorithms Implementation
 * 
 * This header provides comprehensive implementations of essential graph algorithms
 * commonly used in competitive programming. It includes:
 * - Dijkstra's Algorithm for shortest path in weighted graphs
 * - Bellman-Ford Algorithm for shortest path with negative weights
 * - Kruskal's Algorithm for Minimum Spanning Tree
 * - Depth-First Search (DFS) and Breadth-First Search (BFS)
 * - Topological Sort
 * - Cycle Detection
 * 
 * All algorithms are optimized for competitive programming with proper
 * time and space complexity considerations.
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include "utilities/common.hpp"
#include "data_structures/dsu.hpp"

class GraphAlgorithms {
private:
    static const int INF = 1e18;
    
public:
    /**
     * @brief Dijkstra's Algorithm for shortest path in weighted graphs
     * @param graph Adjacency list representation of the graph
     * @param start Starting vertex
     * @return Vector of shortest distances from start to all vertices
     * 
     * Time Complexity: O((V + E) log V)
     * Space Complexity: O(V + E)
     */
    static vi dijkstra(const vector<vpii>& graph, int start) {
        int n = sz(graph);
        vi dist(n, INF);
        priority_queue<pii, vpii, greater<pii>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            int d = pq.top().ff;
            int u = pq.top().ss;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto& edge : graph[u]) {
                int v = edge.ff;
                int w = edge.ss;
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    /**
     * @brief Bellman-Ford Algorithm for shortest path with negative weights
     * @param edges List of edges (u, v, weight)
     * @param n Number of vertices
     * @param start Starting vertex
     * @return Pair of (distances, has_negative_cycle)
     * 
     * Time Complexity: O(VE)
     * Space Complexity: O(V)
     */
    static pair<vi, bool> bellmanFord(const vector<tuple<int, int, int>>& edges, int n, int start) {
        vi dist(n, INF);
        dist[start] = 0;
        
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
     * @brief Kruskal's Algorithm for Minimum Spanning Tree
     * @param edges List of edges (u, v, weight)
     * @param n Number of vertices
     * @return Pair of (MST_weight, MST_edges)
     * 
     * Time Complexity: O(E log E)
     * Space Complexity: O(V + E)
     */
    static pair<int, vector<pii>> kruskal(const vector<tuple<int, int, int>>& edges, int n) {
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
     * @brief Depth-First Search
     * @param graph Adjacency list representation
     * @param start Starting vertex
     * @param visited Reference to visited array
     * @param result Reference to result vector for traversal order
     */
    static void dfs(const vector<vi>& graph, int start, vector<bool>& visited, vi& result) {
        visited[start] = true;
        result.pb(start);
        
        for (int neighbor : graph[start]) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, visited, result);
            }
        }
    }
    
    /**
     * @brief Breadth-First Search
     * @param graph Adjacency list representation
     * @param start Starting vertex
     * @return Vector of vertices in BFS order
     */
    static vi bfs(const vector<vi>& graph, int start) {
        int n = sz(graph);
        vector<bool> visited(n, false);
        queue<int> q;
        vi result;
        
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.pb(u);
            
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return result;
    }
    
    /**
     * @brief Topological Sort using DFS
     * @param graph Adjacency list representation
     * @return Vector of vertices in topological order
     */
    static vi topologicalSort(const vector<vi>& graph) {
        int n = sz(graph);
        vector<bool> visited(n, false);
        vi result;
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (int v : graph[u]) {
                if (!visited[v]) {
                    dfs(v);
                }
            }
            result.pb(u);
        };
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        
        reverse(all(result));
        return result;
    }
    
    /**
     * @brief Check if graph has a cycle using DFS
     * @param graph Adjacency list representation
     * @return true if cycle exists, false otherwise
     */
    static bool hasCycle(const vector<vi>& graph) {
        int n = sz(graph);
        vector<int> color(n, 0); // 0: white, 1: gray, 2: black
        
        function<bool(int)> dfs = [&](int u) {
            color[u] = 1; // gray
            for (int v : graph[u]) {
                if (color[v] == 1) return true; // back edge found
                if (color[v] == 0 && dfs(v)) return true;
            }
            color[u] = 2; // black
            return false;
        };
        
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && dfs(i)) {
                return true;
            }
        }
        
        return false;
    }
};

#endif // GRAPH_ALGORITHMS_H
