#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;
using ull = unsigned long long;

ui N;
void solve() {
    cin >> N;
    
    ull ans = 0;
    for (int pos = 0; pos < 31; pos++) {
        ans += (((N + 1) >> (pos + 1)) << pos);
        ui rem = (N + 1) & ((1u << (pos + 1)) - 1);
        
        int set_rem = rem - (1u << pos);
        if (set_rem > 0) ans += set_rem;
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