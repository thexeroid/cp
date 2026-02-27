#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001];
void solve() {    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int l = 0, r = N - 1;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;

        if (arr[m1] < arr[m2]) {
            l = m1;
        } else if (arr[m1] > arr[m2]) {
            r = m2;
        } else {
            l = m1;
            r = m2;
        }
    }

    int peak = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] > arr[peak]) peak = i;
    }

    cout << peak << endl;
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