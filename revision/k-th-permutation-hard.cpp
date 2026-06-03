#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, k;

int start;
int fact[20];
bool used[20];

void init() {
    cin >> n >> k;
    start = max(1, n - 12);

    fact[0] = 1;
    for (int num = 1; num <= 12; num++) fact[num] = num * fact[num - 1];
}

int get_xth_unused_el(int x) {
    int cnter = 0;

    for (int ch = start; ch <= n; ch++) {
        if (!used[ch - start + 1]) cnter++;
        if (cnter == x) return ch;
    }

    return -1;
}

void rec(int level, int k) {
    if (level > n) return;

    int den = fact[n - level];

    int ch = get_xth_unused_el(k / den + 1);

    if (ch != -1) {
        cout << ch << sp;

        used[ch - start + 1] = 1;
        rec(level + 1, k % den);
        used[ch - start + 1] = 0;
    }
}

void solve() {
    init();

    for (int num = 1; num < start; num++) cout << num << sp;

    rec(start, k - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}