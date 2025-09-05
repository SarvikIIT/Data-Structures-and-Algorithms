/**
 * @file frog_jump.cpp
 * @brief Frog Jump Problem (1D DP)
 * 
 * This file contains implementations for the frog jump problem
 * where a frog can jump 1 or 2 steps at a time, and we need to
 * find the minimum cost to reach the end.
 * 
 * Problem: Frog can jump 1 or 2 steps, find minimum cost
 * Time Complexity: O(n)
 * Space Complexity: O(n) for memoization, O(1) for tabulation
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
const int MAXN = 2e5 + 5;

int N; 
int h[MAXN];
int dp[MAXN];

// Memoization approach
int soln(int n){
    if(n == N - 1) return 0;
    if(n == N - 2) return abs(h[N - 1] - h[N - 2]);
    if(dp[n] != -1) return dp[n];
    return dp[n] = min(
        abs(h[n + 1] - h[n]) + soln(n + 1),
        abs(h[n + 2] - h[n]) + soln(n + 2)
    );
}

void solve() {
    cin >> N;
    rep(i, 0, N) cin >> h[i];
    memset(dp, -1, sizeof(dp));
    cout << soln(0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; // comment this line if single test case
    while(t--) solve();
    return 0;
}

/*
// Bottom Up Solution:

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

int h[N], dp[N];

void solve() {
    int n;
    cin >> n;
    rep(i, 0, n) cin >> h[i];
    memset(dp, -1, sizeof(dp));

    dp[n-1]=0;
    dp[n-2]=abs(h[n-1]-h[n-2]);

     repr(i, n - 3, 0) {
        dp[i] = min(
            abs(h[i + 1] - h[i]) + dp[i + 1],
            abs(h[i + 2] - h[i]) + dp[i + 2]
        );
    }
    cout<<dp[0]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;  // comment this line if single test case
    while(t--) solve();
    return 0;
}
*/
