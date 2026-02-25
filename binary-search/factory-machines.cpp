#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"


int n, t;
int arr[200001];

bool check(int T) {
    int items = 0;
    for (int i = 0; i < n; i++) {
        items += T / arr[i];
    }

    return items >= t;
}

void solve() {
    cin >> n >> t;
    int t_min = LLONG_MAX, t_max = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        t_min = min(t_min, num);
        t_max = max(t_max, num);
        arr[i] = num;
    }

    int ans = -1;
    int l = (t * t_min) / n, r = (n + t - 1) * t_max / n;
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