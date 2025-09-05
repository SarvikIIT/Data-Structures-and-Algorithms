/**
 * @file bfs_dfs.hpp
 * @brief Breadth-First Search and Depth-First Search Algorithms
 * 
 * This header provides implementations of BFS and DFS algorithms for graph traversal
 * and various graph-related problems.
 * 
 * Features:
 * - BFS traversal
 * - DFS traversal
 * - Topological sort
 * - Cycle detection
 * - Connected components
 * - Shortest path in unweighted graphs
 * 
 * Time Complexity:
 * - BFS/DFS: O(V + E)
 * - Topological sort: O(V + E)
 * - Cycle detection: O(V + E)
 * 
 * Space Complexity: O(V + E)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BFS_DFS_HPP
#define BFS_DFS_HPP

#include "utilities/common.hpp"

class BFSDFS {
public:
    /**
     * @brief Breadth-First Search traversal
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
     * @brief Depth-First Search traversal
     * @param graph Adjacency list representation
     * @param start Starting vertex
     * @return Vector of vertices in DFS order
     */
    static vi dfs(const vector<vi>& graph, int start) {
        int n = sz(graph);
        vector<bool> visited(n, false);
        vi result;
        
        function<void(int)> dfsHelper = [&](int u) {
            visited[u] = true;
            result.pb(u);
            
            for (int v : graph[u]) {
                if (!visited[v]) {
                    dfsHelper(v);
                }
            }
        };
        
        dfsHelper(start);
        return result;
    }
    
    /**
     * @brief Topological sort using DFS
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
    
    /**
     * @brief Find connected components
     * @param graph Adjacency list representation
     * @return Vector of vectors, each containing vertices in a component
     */
    static vector<vi> connectedComponents(const vector<vi>& graph) {
        int n = sz(graph);
        vector<bool> visited(n, false);
        vector<vi> components;
        
        function<void(int, vi&)> dfs = [&](int u, vi& component) {
            visited[u] = true;
            component.pb(u);
            
            for (int v : graph[u]) {
                if (!visited[v]) {
                    dfs(v, component);
                }
            }
        };
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vi component;
                dfs(i, component);
                components.pb(component);
            }
        }
        
        return components;
    }
    
    /**
     * @brief Shortest path in unweighted graph using BFS
     * @param graph Adjacency list representation
     * @param start Starting vertex
     * @return Vector of shortest distances from start
     */
    static vi shortestPathUnweighted(const vector<vi>& graph, int start) {
        int n = sz(graph);
        vi dist(n, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        return dist;
    }
};

#endif // BFS_DFS_HPP
