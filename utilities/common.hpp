/**
 * @file common.h
 * @brief Common utilities and type definitions for competitive programming
 * 
 * This header provides essential type definitions, macros, and utility functions
 * commonly used in competitive programming. It includes:
 * - Standard type aliases for cleaner code
 * - Common macros for competitive programming
 * - Grid direction vectors for 2D problems
 * - Fast I/O utilities
 * - String and binary manipulation functions
 * - Vector utility functions
 * 
 * @author Sarvik
 * @version 1.0
 */

#ifndef COMMON_H
#define COMMON_H

#include <bits/stdc++.h>
using namespace std;

// Type definitions for competitive programming
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define each(a,x) for (auto& a : x)

using ll = long long;
using ld = long double;
using str = string;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

// Grid directions (8-directional)
const vi dx = {-1, 0, 1, 0, -1, -1, 1, 1};
const vi dy = {0, 1, 0, -1, -1, 1, -1, 1};

// Fast I/O
inline void fastscan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

// Utility functions
inline bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

inline bool isPalindrome(string s) {
    int n = sz(s);
    rep(i, 0, n/2) if(s[i] != s[n-1-i]) return false;
    return true;
}

inline string toBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = char('0' + n % 2) + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary;
}

inline int fromBinary(string binary) {
    int num = 0;
    for (char c : binary) {
        num = num * 2 + (c - '0');
    }
    return num;
}

template<typename T>
inline void sortVector(vector<T>& arr) { 
    sort(all(arr)); 
}

template<typename T>
inline void reverseVector(vector<T>& arr) { 
    reverse(all(arr)); 
}

#endif // COMMON_H
