#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

int N;
void solve() {
    cin >> N;

    ui ans = 0;
    for (int i = 0; i < N; i++) {
        ui num;
        cin >> num;

        ans ^= num;
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