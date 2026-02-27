#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
map<int, int> mp;

void reset() {
    mp.clear();
}

bool check(int B) {
    int acc = 0;
    for (auto it: mp) {
        acc += min(it.second, B);
        if (acc >= B * K) return true;
    }

    return false;
}

void solve() {  
    reset();

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        mp[num]++;
    }

    int ans = 0;
    int l = 1, r = N / K;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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