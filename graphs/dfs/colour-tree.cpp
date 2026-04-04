#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, m;
int degree[100001];

void solve() {
    cin >> n;
    m = n - 1;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        degree[from]++;
        degree[to]++;
        ans = max(ans, degree[from] + 1);
        ans = max(ans, degree[to] + 1);
    }

    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}