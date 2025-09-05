/**
 * @file frog_jump_k_steps.cpp
 * @brief Frog Jump Problem with K Steps (1D DP)
 * 
 * This file contains implementations for the frog jump problem
 * where a frog can jump up to K steps at a time, and we need to
 * find the minimum cost to reach the end.
 * 
 * Problem: Frog can jump up to K steps, find minimum cost
 * Time Complexity: O(n * k)
 * Space Complexity: O(n) for memoization, O(1) for tabulation
 * 
 * @author Sarvik
 * @version 1.0
 */

#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)

// Typedefs
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
const int MAXN = 2e5 + 5;

// Math utilities
ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x %= MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y >>= 1; } return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Globals
int N, k;
int h[MAXN], dp[MAXN];

// DP function - Memoization approach
int soln(int n) {
    if (n == N - 1) return 0;
    if (dp[n] != -1) return dp[n];

    int val = INF;
    rep(i, 1, k + 1) {
        if (n + i < N) {
            val = min(val, abs(h[n + i] - h[n]) + soln(n + i));
        }
    }
    return dp[n] = val;
}

void solve() {
    cin >> N >> k;
    rep(i, 0, N) cin >> h[i];
    memset(dp, -1, sizeof(dp));
    cout << soln(0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; // Uncomment if multiple testcases
    while (t--) solve();
    return 0;
}

/*
//Bottom up solution:

#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)

// Typedefs
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
const int MAXN = 2e5 + 5;

// Math utilities
ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x %= MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y >>= 1; } return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Globals
int N, k;
int h[MAXN], dp[MAXN];

void solve() {
    cin >> N >> k;
    rep(i, 0, N) cin >> h[i];

    dp[N - 1] = 0;

    repr(i, N - 2, 0) {
        int val = INF;
        rep(j, 1, k + 1) {
            if (i + j < N) {
                val = min(val, dp[i + j] + abs(h[i] - h[i + j]));
            }
        }
        dp[i] = val;
    }

    cout << dp[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; // Uncomment for multiple testcases
    while (t--) solve();
    return 0;
}
*/
