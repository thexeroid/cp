#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

ll n;
string S;
vector<ll> dp;

bool is_valid(ll s, ll e) {
    if (e >= n || S[s] == '0') return false;

    ll num = 0;
    for (ll i = s; i <= e; i++) {
        num = num * 10 + (S[i] - '0');
    }

    return 1 <= num && num <= 26;
}

ll rec(ll level) {
    // pruning
    // base case
    if (level == n) return 1;
 
    // cache return
    if (dp[level] != -1) return dp[level];
 
    // transitions
    ll ans = 0;
    for (ll dx = 0; dx < 2; dx++) {
        if (is_valid(level, level + dx)) {
            ans += rec(level + dx + 1);
        }
    }
    // save and return
    return dp[level] = ans;
}

void solve() {
    n = S.size();
    dp.assign(n + 1, -1);

    print(rec(0));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> tests;
    
    while (cin >> S) {
        if (S == "0") continue;
        solve();
    }

    return 0;
}