/**
 * @file dijkstra.hpp
 * @brief Dijkstra's Algorithm for Shortest Path
 * 
 * This header provides an implementation of Dijkstra's algorithm for finding
 * the shortest path from a source vertex to all other vertices in a weighted graph.
 * 
 * Features:
 * - Single source shortest path
 * - Works with non-negative edge weights
 * - Uses priority queue for efficiency
 * - Returns distances to all vertices
 * 
 * Time Complexity: O((V + E) log V)
 * Space Complexity: O(V + E)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "utilities/common.hpp"

class Dijkstra {
public:
    /**
     * @brief Find shortest distances from source to all vertices
     * @param graph Adjacency list representation of the graph
     * @param source Starting vertex
     * @return Vector of shortest distances from source to all vertices
     */
    static vi shortestPath(const vector<vpii>& graph, int source) {
        int n = sz(graph);
        vi dist(n, INF);
        priority_queue<pii, vpii, greater<pii>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
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
     * @brief Find shortest path from source to target
     * @param graph Adjacency list representation of the graph
     * @param source Starting vertex
     * @param target Destination vertex
     * @return Pair of (shortest distance, path as vector of vertices)
     */
    static pair<int, vi> shortestPathToTarget(const vector<vpii>& graph, int source, int target) {
        int n = sz(graph);
        vi dist(n, INF);
        vi parent(n, -1);
        priority_queue<pii, vpii, greater<pii>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int d = pq.top().ff;
            int u = pq.top().ss;
            pq.pop();
            
            if (u == target) break;
            if (d > dist[u]) continue;
            
            for (auto& edge : graph[u]) {
                int v = edge.ff;
                int w = edge.ss;
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
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

#endif // DIJKSTRA_HPP

