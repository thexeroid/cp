#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, target;
int arr[1001];
void solve() {    
    cin >> N >> target;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    int ans = LLONG_MAX;
    for (int i = 0; i < N - 2; i++) {
        int lcl_target = target - arr[i]; 

        int l = i + 1, r = N - 1;
        while (l < r) {
            int ts = arr[l] + arr[r];
            ans = min(ans, abs(ts - lcl_target));

            if (ts > lcl_target) r--;
            else if (ts < lcl_target) l++;
            else {
                break;
            }
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