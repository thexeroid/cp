#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int arr[100001];

bool check(int D) {
    int cnt_studs = 1;
    int last_pos = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[last_pos] >= D) {
            last_pos = i;
            cnt_studs++;
            if (cnt_studs >= K) return true;
        }
    }

    return false;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int ans = -1;
    int l = 1, r = arr[N - 1] - arr[0];
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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