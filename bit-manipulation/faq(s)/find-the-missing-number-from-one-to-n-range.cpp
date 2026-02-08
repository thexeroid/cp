#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

ui find_xor_one_to_n(ui n) {
    ui rem = n % 4;
    
    ui ans = 0;
    switch(rem) {
        case 0: ans = n; break;
        case 1: ans = 1; break;
        case 2: ans = n + 1; break;
        case 3: ans = 0; break;
    }

    return ans;
}

ui N;
void solve() {
    cin >> N;
    ui ans = 0; 
    for (int i = 0; i < N; i++) {
        ui num;
        cin >> num;

        ans ^= num;
    }
    
    ans ^= find_xor_one_to_n(N + 1);

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