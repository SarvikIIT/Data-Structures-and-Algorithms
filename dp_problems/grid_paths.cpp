/**
 * @file grid_paths.cpp
 * @brief Grid Paths Problem (2D DP)
 * 
 * This file contains implementations for counting the number of
 * paths from top-left to bottom-right in a grid with obstacles.
 * 
 * Problem: Count paths in grid with obstacles
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
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
const int N = 2e3;

ll mod(ll x) { return ((x % MOD + MOD) % MOD); }
ll add(ll a, ll b) { return mod(mod(a) + mod(b)); }
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); }
ll power(ll x, ll y) { ll res = 1; x = x % MOD; while (y > 0) { if (y & 1) res = mul(res, x); x = mul(x, x); y = y >> 1; } return res; }

ll gcd(ll a, ll b) { if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int n;

void solve() {
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Check if starting position is blocked
    if (grid[0][0] == '*') {
        cout << 0 << '\n';
        return;
    }

    dp[0][0] = 1;

    // Fill first row
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == '.') dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }
    
    // Fill first column
    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == '.') dp[0][j] = dp[0][j-1];
        else dp[0][j] = 0;
    }
    
    // Fill rest of the grid
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    cout << dp[n-1][n-1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
   // cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}
