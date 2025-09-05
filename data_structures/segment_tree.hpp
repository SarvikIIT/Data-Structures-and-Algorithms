/**
 * @file segment_tree.h
 * @brief Segment Tree with Lazy Propagation for Range Queries and Updates
 * 
 * This header provides a comprehensive implementation of a segment tree data structure
 * optimized for competitive programming. It supports:
 * - Range minimum queries (RMQ)
 * - Point updates
 * - Range updates with lazy propagation
 * - Efficient O(log n) operations for both queries and updates
 * 
 * The implementation uses lazy propagation to handle range updates efficiently,
 * making it suitable for problems involving range modifications and queries.
 * 
 * Time Complexity:
 * - Construction: O(n)
 * - Range Query: O(log n)
 * - Point Update: O(log n)
 * - Range Update: O(log n)
 * 
 * Space Complexity: O(4n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include "utilities/common.hpp"

class SegmentTree {
private:
    vi ar, segment_tree, lazy;
    int n;
    
public:
    SegmentTree(vi& arr) {
        ar = arr;
        n = sz(arr);
        segment_tree.resize(4 * n, INF);
        lazy.resize(4 * n, 0);
        buildTree(0, n - 1, 1);
    }
    
    void buildTree(int start_index, int end_index, int segment_index) {
        if (start_index == end_index) {
            segment_tree[segment_index] = ar[start_index];
            return;
        }

        int mid = (start_index + end_index) / 2;
        buildTree(start_index, mid, 2 * segment_index);
        buildTree(mid + 1, end_index, 2 * segment_index + 1);

        segment_tree[segment_index] = min(segment_tree[2 * segment_index], segment_tree[2 * segment_index + 1]);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            segment_tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        rangeUpdate(2 * node, start, mid, l, r, val);
        rangeUpdate(2 * node + 1, mid + 1, end, l, r, val);
        segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
    }

    int query(int start_index, int end_index, int segment_index, int query_start, int query_end) {
        push(segment_index, start_index, end_index);
        if (query_end < start_index || query_start > end_index)
            return INF;
        if (query_start <= start_index && end_index <= query_end)
            return segment_tree[segment_index];

        int mid = (start_index + end_index) / 2;
        int left = query(start_index, mid, 2 * segment_index, query_start, query_end);
        int right = query(mid + 1, end_index, 2 * segment_index + 1, query_start, query_end);

        return min(left, right);
    }
    
    int rangeMin(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }
    
    void updateRange(int l, int r, int val) {
        rangeUpdate(1, 0, n - 1, l, r, val);
    }
    
    void pointUpdate(int pos, int val) {
        rangeUpdate(1, 0, n - 1, pos, pos, val - ar[pos]);
        ar[pos] = val;
    }
};

#endif // SEGMENT_TREE_H
