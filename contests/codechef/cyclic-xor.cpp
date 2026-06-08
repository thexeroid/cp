#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

const ll mod = 998244353;

ll binpow(ll base, ll exp) {
    ll res = 1;
    
    while (exp) {
        if (exp % 2) res = (res * base) % mod;
        
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return res;
}

ll gcd(ll a, ll b) {
    if (a + b == a || a + b == b) return a + b;
    
    return gcd(b, a % b);
}

void solve() {
    ll n, k; cin >> n >> k;
    
    ll temp = n;
    
    ll v1 = 0;
    while (temp % 2 == 0) {
        v1++;
        temp /= 2;
    }
    
    ll m = 1LL << min(v1, k);
    
    ll cycle_cnt = gcd(n, m);
    ll cycle_len = n / cycle_cnt;
    
    ll dim = cycle_len % 3 == 0 ? 2 : 0;

    print(binpow(2, dim * cycle_cnt * k));
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