#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

const ll mod = 998244353;

ll n, k;
ll fact[400001];

void cache() {
    fact[0] = 1;
    for (ll num = 1; num < 400001; num++) {
        fact[num] = (num * fact[num - 1]) % mod;
    }
}

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = (res * base) % mod;
        
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return res;
}

ll inv(ll num) {
    return binpow(num, mod - 2);
}

ll C(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    
    ll num = fact[n];
    ll den = (fact[n - r] * fact[r]) % mod;
    
    return (num * inv(den)) % mod;
}

void init() {
    cin >> n >> k;
}

void solve() {
    init();
    
    ll ans = 0;
    for (ll mx = 1; mx <= k; mx++) {
        ll prefix = (binpow(mx, k) - binpow(mx - 1, k)) % mod;
        ll suffix = C(n - mx, n - k);
        
        ans = (ans + (prefix * suffix) % mod) % mod;
    }
    
    ans = (ans + mod) % mod;
    
    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cache();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}