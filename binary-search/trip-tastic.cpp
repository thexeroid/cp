/*
Link: https://www.codechef.com/problems/TRPTSTIC
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, M, K;

int sum_rect(vector<vector<int>> &PS, int x1, int y1, int x2, int y2) {
    x1 = max(0LL, x1), y1 = max(0LL, y1);
    x2 = min(x2, N - 1), y2 = min(y2, M - 1);
    
    int ans = PS[x2][y2];
    if (x1 > 0 && y1 > 0) ans += PS[x1 - 1][y1 - 1];
    if (x1 > 0) ans -= PS[x1 - 1][y2];
    if (y1 > 0) ans -= PS[x2][y1 - 1];

    return ans;
}

bool check(int D, vector<vector<int>> &PS) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x1 = i - D, y1 = j - D;
            int x2 = i + D, y2 = j + D;

            int seats = sum_rect(PS, x1, y1, x2, y2);
            if (sum_rect(PS, i, j, i, j) != 0 && seats >= K + 1) return true;
        }
    }

    return false;
}

void solve() {
    cin >> N >> M >> K;
    vector<vector<int>> PS(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            PS[i][j] = num;
            if (i > 0 && j > 0) PS[i][j] -= PS[i - 1][j - 1];
            if (i > 0) PS[i][j] += PS[i - 1][j];
            if (j > 0) PS[i][j] += PS[i][j - 1];
        }
    }

    int ans = -1;

    int l = 0, r = max(M - 1, N - 1);
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid, PS)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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