#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, S;

bool check(int X) {
    int copy_X = X;
    int digit_sum = 0;
    while (copy_X) {
        digit_sum += (copy_X % 10);
        copy_X /= 10;
    }

    return (X - digit_sum) >= S;
} 


void solve() {
    cin >> N >> S;

    int ans = N + 1;
    int l = 1, r = N;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << (N - ans + 1) << endl;
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