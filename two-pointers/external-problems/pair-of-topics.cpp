#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int N;
int A[200001];
int C[200001];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        int bi; cin >> bi;

        C[i] = A[i] - bi;
    }

    sort(C, C + N);
}

void solve() {
    init();

    ll ans = 0;

    int l = 0, r = N - 1;
    while (l < r) {
        if (C[l] + C[r] > 0) {
            ans += (r - l);
            r--;
        } else {
            l++;
        }
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}