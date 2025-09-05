/**
 * @file dice_combinations.cpp
 * @brief Dice Combinations Problem (1D DP)
 * 
 * This file contains implementations for counting the number of
 * ways to get a sum using dice throws.
 * 
 * Problem: Count ways to get sum n using dice (1-6)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * @author Sarvik
 * @version 1.0
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)

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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x = x % MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y = y >> 1; } return res; }

ll gcd(ll a, ll b) { if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int n;
vi poss = {1, 2, 3, 4, 5, 6};
vi dp;

void solve() {
    cin >> n;
    dp.assign(n + 1, 0);
    dp[0] = 1;  // Base case: 1 way to get sum 0

    // Fill DP table
    for(int i = 0; i <= n; ++i) {
        for(auto x : poss) {
            if(i - x >= 0) {
                dp[i] += dp[i - x];
                dp[i] = mod(dp[i]);
            }
        }
    }
    
    cout << dp[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}
