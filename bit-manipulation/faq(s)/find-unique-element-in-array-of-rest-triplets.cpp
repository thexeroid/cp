#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

int N;
ui arr[100000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    ui ans = 0;
    for (int pos = 0; pos < 32; pos++) {
        int bit_sum = 0;
        for (int i = 0; i < N; i++) {
            ui num = arr[i];
            bit_sum += (num >> pos) & 1;
        }
        if (bit_sum % 3) ans |= (1u << pos);
    }

    cout << (int)ans << endl;
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