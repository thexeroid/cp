#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int arr[100001];
void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    int mn = arr[0], mx = arr[N - 1];
    int cnt_min = 1, cnt_max = 1;

    int l = 0, r = N - 1;
    while (l < r && K > 0) {
        while (l + 1 <= r && arr[l] == arr[l + 1]) {
            cnt_min++;
            l++;
        }

        while (l <= r - 1 && arr[r - 1] == arr[r]) {
            cnt_max++;
            r--;
        }

        if (l >= r) break;

        int cost_l = (arr[l + 1] - arr[l]) * cnt_min;
        int cost_r = (arr[r] - arr[r - 1]) * cnt_max;

        if (cost_l <= cost_r && cost_l <= K) {
            K -= cost_l;
            l++;
            mn = arr[l];
            cnt_min++;
        } else if (cost_r < cost_l && cost_r <= K) {
            K-= cost_r;
            r--;
            mx = arr[r];
            cnt_max++;
        } else {
            if (cost_l <= cost_r) {
                mn += K / cnt_min;
            } else {
                mx -= K / cnt_max;
            }

            break;
        }
    }

    cout << (mx - mn) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}