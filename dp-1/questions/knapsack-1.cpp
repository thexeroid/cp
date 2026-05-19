#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

using P = pair<ll, ll>;
#define F first
#define S second

ll n, w;
vector<P> arr;
vector<vector<ll>> dp;

void input() {
    cin >> n >> w;
    arr.resize(n);
    dp.assign(n + 5, vector<ll>(w + 5, -1));
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].F >> arr[i].S;
    }
}

ll rec(ll level, ll capacity) {
    // pruning
    if (capacity < 0) return 0;

    // base case
    if (level == n) return 0; 

    // return if saved
    if (dp[level][capacity] != -1) return dp[level][capacity];

    // transitions
    ll ans = rec(level + 1, capacity);
    if (arr[level].F <= capacity) {
        ans = max(ans, rec(level + 1, capacity - arr[level].F) + arr[level].S);
    }

    // save and return
    return dp[level][capacity] = ans;
}

void solve() {
    input();

    print(rec(0, w));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}