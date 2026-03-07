#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;
int queens[14];

int ans = 0;

int dx[] = {-2, -2, -1, -1};
int dy[] = {-1, 1, -2, 2};

bool check(int row, int col) {
    for (int pqr = 0; pqr < row; pqr++) {
        int pqc = queens[pqr];
        if (pqc == col || abs(row - pqr) == abs(col - pqc)) return false;
    }

    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i], ny = col + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (queens[nx] == ny) return false;
        }
    }

    return true;
}

void rec(int level) {
    if (level == n) {
        ans++;
        return;
    }

    for (int ch = 0; ch < n; ch++) {
        if (check(level, ch)) {
            queens[level] = ch;
            rec(level + 1);
            queens[level] = -1;
        }
    }
}

void solve() {    
    cin >> n;
    memset(queens, -1, sizeof(queens));

    rec(0);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}