#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

void solve() {
    ll N, X;
    cin >> N >> X;

    ll arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    bool ans = false;
    map<ll, ll> mp;
    for (int b = N - 3; b >= 1; b--) {
        int c = b + 1;
        for (int d = c + 1; d < N; d++) {
            mp[X - arr[c] - arr[d]] = 1;
        }

        for (int a = b - 1; a >= 0; a--) {
            if (mp.count(arr[a] + arr[b])) {
                ans = true;
                break;
            }
        }

        if (ans) break;
    }

    print((ans ? "YES" : "NO"));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}