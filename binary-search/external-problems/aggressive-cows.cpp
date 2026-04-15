/*
Link: https://www.spoj.com/problems/AGGRCOW/
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int N, C;
vector<int> arr;

void init() {
    cin >> N >> C;
    arr.resize(N);

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
}

bool check(int X) {
    int cows_placed = 1;
    int last_pos = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[last_pos] >= X) {
            last_pos = i;
            cows_placed++;

            if (cows_placed >= C) return true;
        }
    }

    return false;
}

void solve() {
    init();

    int s = 1, e = arr[N - 1] - arr[0];
    int ans = s;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (check(mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    print(ans);
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