#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool check(vector<int> &arr, int idx) {
    int N = arr.size();
    return arr[idx] <= arr[N - 1];
}

void solve() {    
    int N;
    cin >> N;
    
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr.push_back(num);
    }

    int ans = -1;

    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(arr, mid)) {
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