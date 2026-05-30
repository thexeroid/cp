#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int rec(int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;

    return rec(num - 1) + rec(num - 2);
}

void solve() {
    int n;
    cin >> n;
    
    print(rec(n));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}