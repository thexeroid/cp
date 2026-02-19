#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int arr[100001];
void solve() {    
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];

    int sum = 0;
    int ans = 0;
    
    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (sum + arr[head + 1] <= K)) {
            head++;
            sum += arr[head];
        }

        ans += (head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            sum -= arr[tail];
            tail++;
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