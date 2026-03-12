#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int N;
int used[20];
int start = 1;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    int fact = 5;
    while (fact <= num / fact) {
        if (num % fact == 0) return false;
        if (num % (fact + 2) == 0) return false;
        fact += 6;
    }

    return true;
}

bool check(int level, int prev, int ch) {
    if (used[ch]) return false;

    return is_prime(prev + ch);
}

int rec(int level, int prev) {
    if (level == N) {
        return is_prime(start + prev);
    }

    int ans = 0;
    for (int ch = 1; ch <= N; ch++) {
        if (check(level, prev, ch)) {
            used[ch] = 1;
            ans += rec(level + 1, ch);
            used[ch] = 0;
        }
    }
    
    return ans;
}

void init() {
    used[start] = 1;
    cin >> N;
}

void solve() {
    init();
    int ans = 0;
    if (N % 2 == 0) ans = rec(1, start);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}