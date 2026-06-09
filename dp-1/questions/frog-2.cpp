#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, k;
int arr[100001];
int dp[100001];

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, -1, n * sizeof(arr[0]));
}

int rec(int level) {
    // base case
    if (level == 0) return 0;

    // early return
    if (dp[level] != -1) return dp[level];

    // processing
    int ans = INT_MAX;
    for (int i = level - k; i < level; i++) {
        if (i >= 0) ans = min(ans, rec(i) + abs(arr[i] - arr[level]));
    }

    // save and return
    return dp[level] = ans;
}

void solve() {
    init();
    
    print(rec(n - 1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}