#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

ll n, k;
ll fact[13];
bool used[13];
ll st;

void init() {
    fact[0] = 1;

    for (ll num = 1; num <= 12; num++) {
        fact[num] = num * fact[num - 1];
    }
}

ll find_choice(ll choice_num) {
    ll cnter = 0;
    for (ll ch = st + 1; ch <= n; ch++) {
        if (used[ch - st - 1]) continue;
        
        if (cnter == choice_num) return ch;
        cnter++;
    }

    return -1;
}

void rec(ll level, ll k) {
    if (level == n) {
        cout << endl;
        return;
    }

    ll fct = fact[n - 1 - level];
    ll choice_num = k / fct;
    
    ll choice = find_choice(choice_num);
    if (choice != -1) {
        cout << choice << " ";
        used[choice - st - 1] = 1;
        rec(level + 1, k % fct);
        used[choice - st - 1] = 0;
    }
}

void solve() {    
    cin >> n >> k;
    k--;

    st = max(0LL, n - 13);
    for (ll i = 0; i < st; i++) {
        cout << (i + 1) << " ";
    }

    rec(st, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}