#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

void solve_iterative(ui num) {
    for (int pos = 31; pos >= 0; pos--) {
        cout << ((num >> pos) & 1);
    }
    cout << endl;
}

void solve_recursive(ui num, int pos) {
    if (pos > 31) return;

    solve_recursive(num >> 1, pos + 1);
    cout << (num % 2);
    if (pos == 0) cout << endl;
}

void solve() {
    ui num;
    cin >> num;

    solve_iterative(num);
    solve_recursive(num, 0);
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