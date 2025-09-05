/**
 * @file subset_sum.cpp
 * @brief Subset Sum Problem (Knapsack DP)
 * 
 * This file contains implementations for the subset sum problem
 * where we need to find all possible sums that can be formed
 * using elements from the given array.
 * 
 * Problem: Find all possible sums using array elements
 * Time Complexity: O(n * sum)
 * Space Complexity: O(n * sum)
 * 
 * @author Sarvik
 * @version 1.0
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x)(x).begin(), (x).end()
#define sz(x)((int)(x).size())
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)

using ll = long long;
using ld = long double;
using str = string;
using vi = vector < int > ;
using vl = vector < ll > ;
using vvi = vector < vi > ;
using vvl = vector < vl > ;
using pii = pair < int, int > ;
using pll = pair < ll, ll > ;
using vpii = vector < pii > ;
using vpll = vector < pll > ;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

ll mod(ll x) {
    return ((x % MOD + MOD) % MOD);
}
ll add(ll a, ll b) {
    return mod(mod(a) + mod(b));
}
ll mul(ll a, ll b) {
    return mod(mod(a) * mod(b));
}
ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
        y = y >> 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    vi c(n);
    int sum = 0;
    rep(i, 0, n) {
        cin >> c[i];
        sum += c[i];
    }

    // DP table: dp[i][j] = true if sum j can be formed using first i elements
    vector < vector < bool >> dp(n + 1, vector < bool > (sum + 1, false));
    dp[0][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            // Don't take current element
            dp[i][j] = dp[i - 1][j];
            // Take current element if possible
            if (j - c[i - 1] >= 0)
                dp[i][j] = dp[i][j] || dp[i - 1][j - c[i - 1]];
        }
    }

    // Collect all possible sums
    set < int > ans;
    for (int j = 1; j <= sum; j++) {
        if (dp[n][j]) ans.insert(j);
    }

    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while (t--) solve();
    return 0;
}
