#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;
void print(string label, int val, bool newline = false) {
    cout << label << ": " << val << "; ";
    if (newline) cout << endl;
}

bool check(int M) {
    int K = (n * n + 1) / 2;

    int cnt = 0;
    for (int num = 1; num <= n; num++) {
        cnt += min(M / num, n);
    }

    return cnt >= K;
}

void solve() {    
    cin >> n;

    int ans = -1;
    int l = 1, r = n * n;


    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
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

    solve();

    return 0;
}