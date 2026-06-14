#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

using P = pair<ll, ll>;
#define F first
#define S second

const ll mod = 1000000007;

ll n;
ll arr[1001];
P dp[1001];

void input() {
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    fill(dp, dp + n + 1, make_pair(-1, -1));
}

P rec(ll level) {
    // pruning
    // base case
    if (level < 0) return {0, 0};
    
    // cache check
    if (dp[level].F != -1) return dp[level];

    // transition
    ll rlis = 0;
    ll rlis_cnt = 1;
    for (ll prev = 0; prev < level; prev++) {
        if (arr[prev] < arr[level]) {
            P temp = rec(prev);

            if (temp.F > rlis) {
                rlis = temp.F;
                rlis_cnt = temp.S;
            } else if (temp.F == rlis) {
                rlis_cnt = (rlis_cnt + temp.S) % mod;
            }
        }
    }

    // save and return
    return dp[level] = {rlis + 1, rlis_cnt};
}

void solve() {
    input();

    ll rlis = 0;
    ll rlis_cnt = 0;
    for (ll i = 0; i < n; i++) {
        P temp = rec(i);

        if (temp.F > rlis) {
            rlis = temp.F;
            rlis_cnt = temp.S;
        } else if (temp.F == rlis) {
            rlis_cnt = (rlis_cnt + temp.S) % mod;
        }
    }

    print(rlis_cnt);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}