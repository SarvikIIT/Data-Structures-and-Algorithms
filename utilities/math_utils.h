/**
 * @file math_utils.h
 * @brief Mathematical utilities and modular arithmetic functions
 * 
 * This header provides comprehensive mathematical functions optimized for competitive programming:
 * - Modular arithmetic operations (addition, multiplication, exponentiation)
 * - Number theory functions (GCD, LCM, primality testing)
 * - Combinatorics (factorials, combinations with modular arithmetic)
 * - Bit manipulation utilities
 * - Precomputed factorial tables for efficient combination calculations
 * 
 * All operations are designed to work with large numbers using modular arithmetic
 * to prevent overflow in competitive programming contexts.
 * 
 * @author Competitive Programming Library
 * @version 1.0
 */

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "common.h"

// Modular arithmetic
inline ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
inline ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
inline ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }

inline ll power(ll x, ll y) { 
    ll res = 1; 
    x = x % MOD; 
    while (y > 0) { 
        if (y & 1) res = mul(res, x); 
        x = mul(x, x); 
        y = y >> 1; 
    } 
    return res; 
}

inline ll gcd(ll a, ll b) { 
    if (b > a) return gcd(b, a); 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}

inline ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

inline bool isPrime(int n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
}

// Factorials and combinations
vector<ll> fact(N), invfact(N);

void precompute_factorials() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = mul(fact[i-1], i);
    }
    invfact[N-1] = power(fact[N-1], MOD-2);
    for(int i = N-2; i >= 0; i--) {
        invfact[i] = mul(invfact[i+1], i+1);
    }
}

inline ll nCr(int n, int r) {
    if(r > n || r < 0) return 0;
    return mul(fact[n], mul(invfact[r], invfact[n-r]));
}

// Bit manipulation
inline int countBits(int n) {
    return __builtin_popcountll(n);
}

inline int lowestBit(int n) {
    return n & (-n);
}

inline bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

#endif // MATH_UTILS_H
