#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ui = unsigned int;

ui N;
void solve() {
    cin >> N;
    
    ui rem = N % 4;
    ui ans = 0;
    switch (rem) {
        case 0: ans = N; break;
        case 1: ans = 1; break;
        case 2: ans = N + 1; break;
        case 3: ans = 0; break;
        default: break; 
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