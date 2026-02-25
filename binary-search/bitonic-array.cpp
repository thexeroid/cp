#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {    
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int peak = 0;
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid == 0 || arr[mid - 1] < arr[mid]) {
            peak = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    while (Q--) {
        int K;
        cin >> K;

        int ans_left = -1, ans_right = -1;
        int l = 0, r = peak;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= K) {
                ans_left = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        l = peak + 1, r = N - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= K) {
                ans_right = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        bool condition_left = ans_left != -1 && arr[ans_left] == K;
        bool condition_right = ans_right != -1 && arr[ans_right] == K;
        if (condition_left || condition_right) {
            if (condition_left) cout << (ans_left + 1) << " ";
            if (condition_right) cout << (ans_right + 1);
            cout << endl;
        }
    }
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