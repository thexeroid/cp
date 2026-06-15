#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

const int mod = 1000000007;

int n, m, k;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

void init() {
    cin >> n >> m >> k;
    
    board.assign(
        n + 1,
        vector<int>(m + 1)
    );

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    
    dp.assign(
        n + 1,
        vector<vector<int>>(
            m + 1,
            vector<int>(k + 1, -1)
        )
    );
}

int rec(int i, int j, int rem) {
    // pruning
    if (i >= n || j >= m) return 0;
    if (board[i][j] && rem <= 0) return 0;
    
    // base case
    if (i == n - 1 && j == m - 1) return 1;

    // cache check
    if (dp[i][j][rem] != -1) return dp[i][j][rem];

    // transitions
    int ans = 0;
    ans = (ans + rec(i + 1, j, rem - board[i][j])) % mod;
    ans = (ans + rec(i, j + 1, rem - board[i][j])) % mod;

    // save and return
    return dp[i][j][rem] = ans;
}

void solve() {
    init();

    print(rec(0, 0, k));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}