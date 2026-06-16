#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

const int INF = INT_MAX;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dp;

void init() {
    cin >> n >> m;

    board.assign(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    dp.assign(
        n + 1,
        vector<int>(
            m + 1,
            INF
        )
    );
}

int rec(int i, int j) {
    // pruning
    if (i >= n || j >= m) return INF;

    // base case
    if (i == n - 1 && j == m - 1) return board[i][j];

    // cache check
    if (dp[i][j] != INF) return dp[i][j];
    
    // transitions
    int right = rec(i, j + 1);
    int down = rec(i + 1, j);

    int ans = -INF;
    if (j + 1 < m) ans = max(ans, min(board[i][j], board[i][j] + right));
    if (i + 1 < n) ans = max(ans, min(board[i][j], board[i][j] + down));

    // save and return
    return dp[i][j] = ans;
}

void solve() {
    init();

    int ans = max(1, 1 - rec(0, 0));
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