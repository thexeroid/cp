#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

ll n, m;
vector<ll> A[2];

void init() {
    A[0].clear();
    A[1].clear();
    
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        ll num; cin >> num;

        A[i&1].push_back(num);
    }
}

vector<ll> generate(vector<ll> &arr) {
    ll sz = arr.size();

    vector<ll> ans;
    for (ll mask = 0; mask < (1 << sz); mask++) {
        ll sum = 0;
        for (ll pos = 0; pos < sz; pos++) {
            if (mask & (1 << pos)) sum = (sum + arr[pos]) % m;
        }

        ans.push_back(sum);
    }

    sort(ans.begin(), ans.end());

    return ans;
}

void solve() {
    init();

    vector<ll> part1 = generate(A[0]);
    vector<ll> part2 = generate(A[1]);

    ll sz_p1 = part1.size(), sz_p2 = part2.size();

    ll ans = 0;

    ll l = 0, r = sz_p2 - 1;
    while (l < sz_p1 && r >= 0) {
        if (part1[l] + part2[r] >= m) {
            r--;
        } else {
            ans = max(ans, part1[l] + part2[r]);
            l++;
        }
    }


    if (sz_p1 > 0 && sz_p2 > 0) {
        ans = max(ans, part1[sz_p1 - 1] + part2[sz_p2 - 1] - m);
    }
    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}