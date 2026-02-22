#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001];

bool check(int X, int K) {
    int cnt = 0;
    int acc = 0;
    int l = 0, r = -1;
    while (l < N) {
        while (r + 1 < N && acc + arr[r + 1] <= X) {
            acc += arr[r + 1];
            r++;
        }

        cnt += (r - l + 1);

        if (l > r) {
            l++;
            r = l - 1;
        } else {
            acc -= arr[l];
            l++;
        }
    }

    return cnt >= K; 
}

void solve() {    
    cin >> N;

    int ts = 0;
    int mn = INT_MAX;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        ts += num;
        mn = min(mn, num);
    }
    
    int M = N * (N + 1) / 2;
    int K = (M + 1) / 2;

    int ans = -1;
    int s = mn, e = ts;
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (check(mid, K)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
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