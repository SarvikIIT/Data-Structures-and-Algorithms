/**
 * @file binary_search_tree.h
 * @brief Binary Search Tree (BST) Implementation
 * 
 * This header provides a complete implementation of a Binary Search Tree data structure
 * with all standard operations. The BST maintains the property that for each node:
 * - All values in the left subtree are less than the node's value
 * - All values in the right subtree are greater than the node's value
 * 
 * Features:
 * - Insertion of nodes
 * - Deletion of nodes (handles all cases: leaf, one child, two children)
 * - Search for values
 * - In-order traversal (gives sorted sequence)
 * - Finding in-order predecessor
 * 
 * Time Complexity:
 * - Insertion: O(h) where h is height (O(log n) for balanced tree)
 * - Deletion: O(h) where h is height (O(log n) for balanced tree)
 * - Search: O(h) where h is height (O(log n) for balanced tree)
 * - Traversal: O(n)
 * 
 * Space Complexity: O(n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "utilities/common.hpp"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    /**
     * @brief Create a new tree node
     * @param val Value to store in the node
     * @return Pointer to the new node
     */
    TreeNode* createNode(int val) {
        return new TreeNode(val);
    }
    
    /**
     * @brief Search for a value in the BST
     * @param val Value to search for
     * @return Pointer to the node containing val, or nullptr if not found
     */
    TreeNode* search(int val) {
        return searchHelper(root, val);
    }
    
    /**
     * @brief Insert a value into the BST
     * @param val Value to insert
     */
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    /**
     * @brief Delete a value from the BST
     * @param val Value to delete
     */
    void deleteNode(int val) {
        root = deleteHelper(root, val);
    }
    
    /**
     * @brief Perform in-order traversal
     * @return Vector containing values in sorted order
     */
    vi inOrderTraversal() {
        vi result;
        inOrderHelper(root, result);
        return result;
    }
    
    /**
     * @brief Find the in-order predecessor of a value
     * @param val Value to find predecessor for
     * @return Value of the predecessor, or -1 if not found
     */
    int findPredecessor(int val) {
        TreeNode* node = search(val);
        if (!node || !node->left) return -1;
        
        TreeNode* pred = node->left;
        while (pred->right) {
            pred = pred->right;
        }
        return pred->val;
    }
    
    /**
     * @brief Check if the BST is empty
     * @return true if empty, false otherwise
     */
    bool isEmpty() {
        return root == nullptr;
    }
    
private:
    TreeNode* searchHelper(TreeNode* node, int val) {
        if (!node || node->val == val) return node;
        if (val < node->val) return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }
    
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (!node) return createNode(val);
        
        if (val < node->val) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->val) {
            node->right = insertHelper(node->right, val);
        }
        
        return node;
    }
    
    TreeNode* deleteHelper(TreeNode* node, int val) {
        if (!node) return node;
        
        if (val < node->val) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->val) {
            node->right = deleteHelper(node->right, val);
        } else {
            // Node to be deleted found
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                // Node with two children
                TreeNode* pred = findMinNode(node->right);
                node->val = pred->val;
                node->right = deleteHelper(node->right, pred->val);
            }
        }
        
        return node;
    }
    
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    
    void inOrderHelper(TreeNode* node, vi& result) {
        if (!node) return;
        inOrderHelper(node->left, result);
        result.pb(node->val);
        inOrderHelper(node->right, result);
    }
};

#endif // BINARY_SEARCH_TREE_H
