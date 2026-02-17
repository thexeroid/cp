#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

map<int, int> mp;
void solve() {
    mp.clear();
    mp[0] = -1;

    string s;
    cin >> s;

    int N = s.size();

    int ans = 0;
    int mask = 0;

    for (int i = 0; i < N; i++) {
        char ch = s[i];
        int digit = ch - '0';
        mask ^= (1 << digit);

        if (mp.count(mask)) {
            ans = max(ans, i - mp[mask]);
        } else {
            mp[mask] = i;
        }

        for (int k = 0; k < 10; k++) {
            int target = mask ^ (1 << k);
            if (mp.count(target)) {
                ans = max(ans, i - mp[target]);
            }
        }
    }

    cout << ans << endl;
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