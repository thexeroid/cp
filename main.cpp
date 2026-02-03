#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int count_bits(int num) {
    return num == 0 ? 0 : count_bits(num >> 1) + (num & 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        cout << (-1 >> 1) << endl;
        // cout << count_bits(-1) << endl;
        cout << __builtin_popcount(-1) << endl;
    }

    return 0;
}