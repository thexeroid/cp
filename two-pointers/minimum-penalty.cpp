#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, D;
int arr[1000001];

int freq[1000001]{};
int cnt_dist = 0;

void solve() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = INT_MAX;

    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (head - tail + 1 < D)) {
            head++;
            if (freq[arr[head]] == 0) cnt_dist++;
            freq[arr[head]]++;
        }

        if (head - tail + 1 == D)
            ans = min(ans, cnt_dist);
        
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
                cnt_dist--;

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