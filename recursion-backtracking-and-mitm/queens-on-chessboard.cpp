#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n = 8;
char arr[10][10];
int queens[10];

bool check(int row, int col) {
    if (arr[row][col] == '*') return false;
    for (int i = 0; i < row; i++) {
        int j = queens[i];
        if (j == col || abs(row - i) == abs(col - j)) {
            return false;
        }
    }

    return true;
}

int rec(int level) {
    if (level == n) {
        return 1;
    }
        
    int ans = 0;
    for (int ch = 0; ch < n; ch++) {
        if (check(level, ch)) {
            queens[level] = ch;
            ans += rec(level + 1);
            queens[level] = -1;
        }
    }

    return ans;
}

void solve() {
    memset(queens, -1, sizeof(queens));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << rec(0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}