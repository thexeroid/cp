#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int arr[100001];

int ceil(int num, int den) {
    return (num + den - 1) / den;
}

bool check(int D) {
    int points_used = 0;

    for (int i = 1; i < N; i++) {
        int diff = arr[i] - arr[i - 1];
        points_used += ceil(diff, D) - 1;
        if (points_used > K) return false;
    }

    return true;
}

void solve() {  
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
  
    int ans = -1;
    int l = 1, r = 1e9;
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

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}