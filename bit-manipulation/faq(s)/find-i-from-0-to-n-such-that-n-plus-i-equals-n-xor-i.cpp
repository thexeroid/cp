#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

ui n;
void solve() {
    cin >> n;
    
    ui count = 0;
    while (n) {
        if ((n & 1) == 0) count++;
        n >>= 1;
    }

    cout << (1u << count) << endl;
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