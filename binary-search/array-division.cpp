#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, k;
int arr[200001];

bool check(int S) {
    int cnt = 1;
    int acc = 0;

    for (int i = 0; i < n; i++) {
        if (acc + arr[i] <= S) {
            acc += arr[i];
        } else {
            acc = arr[i];
            cnt++;
        }
    }

    return cnt <= k;
}

void solve() {
    cin >> n >> k;
    int mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        mx = max(mx, num);
        sum += num;
    }

    int ans = -1;
    int l = mx, r = sum;
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