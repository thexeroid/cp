#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

ll n, m, p;
ll A[200001];
ll B[200001];

map<ll, ll> freq;
ll missing;

void input() {
    cin >> n >> m >> p;
    for (ll i = 0; i < n; i++) cin >> A[i];
    for (ll i = 0; i < m; i++) {
        cin >> B[i];
        freq[B[i]]++;
    }
    missing = m;
}

void solve() {
    input();

    multiset<ll> ans;
    for (ll q = 0; q < p; q++) {
        // run sliding window
        ll r = q;
        for (ll l = q; l < n; l+=p) {
            while (r < n && missing > 0) {
                if (freq[A[r]] > 0) missing--;
                freq[A[r]]--;

                r += p;
            }

            if (missing == 0 && (r - l) / p == m) {
                ans.insert(l + 1);
            }

            if (l > r) {
                r = l;
            } else {
                freq[A[l]]++;
                if (freq[A[l]] > 0) missing++;
            }
        }
    }

    print(ans.size());
    for (auto el: ans) cout << el << sp;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}