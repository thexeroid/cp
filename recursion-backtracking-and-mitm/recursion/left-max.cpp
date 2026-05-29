#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
int A[100001];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

int rec(int idx) {
    if (idx < 0) return INT_MIN;

    int mx = max(A[idx], rec(idx - 1));
    cout << mx << sp;

    return mx;
}

void solve() {
    input();

    rec(n - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}