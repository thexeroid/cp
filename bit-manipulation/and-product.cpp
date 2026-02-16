#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void refactored() {
    int a, b;
    cin >> a >> b;

    int shifted = 0;
    while (a != b) {
        a >>= 1;
        b >>= 1;
        shifted++;
    }

    cout << (a << shifted) << endl;
}

void solve() {    
    int a, b;
    cin >> a >> b;

    int ans = 0;
    while (a & b) { // common bits from right in order  
        int msb_a = 63 - __builtin_clzll(a); // 64
        int msb_b = 63 - __builtin_clzll(b); // 64

        if (msb_a == msb_b) {
            a = (a & ~(1LL << msb_a)); // 31
            b = (b & ~(1LL << msb_b)); // 31

            ans |= (1LL << msb_a);
        } else a = 0;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        refactored();
    }

    return 0;
}