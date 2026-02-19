#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001];

int freq[100001];
int cnt_dist = 0;

void solve() {    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int K = 0;
    for (int num = 0; num < 100001; num++) {
        K += (freq[num] > 0);
        freq[num] = 0;
    }

    int ans = INT_MAX;

    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (cnt_dist < K)) {
            head++;

            if (freq[arr[head]] == 0) cnt_dist++;
            freq[arr[head]]++;
        }

        if (cnt_dist == K)
            ans = min(ans, head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0) cnt_dist--;

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