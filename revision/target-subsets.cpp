#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, x;
vector<int> A[2];

void init() {
    A[0].clear();
    A[1].clear();

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;

        A[i&1].push_back(num);
    }
}

vector<int> generate(vector<int> &arr) {
    int sz = arr.size();

    vector<int> ans;

    for (int mask = 0; mask < (1 << sz); mask++) {
        int sum = 0;

        for (int pos = 0; pos < sz; pos++) {
            if (mask & (1 << pos)) sum +=  arr[pos];
        }

        ans.push_back(sum);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    init();

    vector<int> part1 = generate(A[0]);
    vector<int> part2 = generate(A[1]);

    ll ans = 0;

    int l = 0, r = part2.size() - 1;
    while (l < part1.size() && r >= 0) {
        if (part1[l] + part2[r] <= x) {
            ans += (r + 1);
            l++;
        } else {
            r--;
        }
    }

    print(ans);
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