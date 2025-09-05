/**
 * @file hash_utils.h
 * @brief Hash utilities and safe unordered containers
 * 
 * This header provides secure hash functions and container wrappers to prevent
 * hash collision attacks in competitive programming. It includes:
 * - Custom hash function using splitmix64 algorithm
 * - Safe unordered_map and unordered_set wrappers
 * - Protection against hash collision attacks
 * - Consistent hashing for better performance
 * 
 * The custom hash function is designed to be fast and provide good distribution
 * while being resistant to collision attacks that can cause performance degradation.
 * 
 * @author Competitive Programming Library
 * @version 1.0
 */

#ifndef HASH_UTILS_H
#define HASH_UTILS_H

#include "common.h"

// Custom hash for unordered containers to avoid hash collision attacks
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Safe hash containers
template<typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;

template<typename T>
using safe_set = unordered_set<T, custom_hash>;

template<typename K>
using safe_unordered_set = unordered_set<K, custom_hash>;

template<typename K, typename V>
using safe_unordered_map = unordered_map<K, V, custom_hash>;

#endif // HASH_UTILS_H
