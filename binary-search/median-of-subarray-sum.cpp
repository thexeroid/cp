#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001];

bool check(int M) {
    int cnt_subarr = N * (N + 1) / 2;
    int K = (cnt_subarr + 1) / 2;

    int ans = 0;
    int acc = 0;

    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && acc + arr[head + 1] <= M) {
            head++;
            acc += arr[head];
        }

        ans += (head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            acc -= arr[tail];
            tail++;
        }
    }

    return ans >= K;
}

void solve() {
    cin >> N;
    int mn = LLONG_MAX, sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        mn = min(mn, num);
        sum += num;
    }

    int ans = -1;
    int l = mn, r = sum;
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