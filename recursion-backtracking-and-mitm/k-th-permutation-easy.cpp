#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, k;
vector<int> freq(10);
vector<int> fact(10);

int get_choice(int term) {
    int ct = 0;
    for (int num = 1; num <= n; num++) {
        if (freq[num] > 0) {
            ct++;
            if (ct == term) {
                return num;
            }
        }
    }

    return -1;
}

void rec(int level, int k) {
    if (level == n) {
        cout << endl;
        return;
    }

    int curr_n = (n - level);

    int num = k;
    int den = fact[curr_n - 1];

    int quo = num / den;
    int rem = num % den;

    int term = quo + (rem > 0);
    int el = get_choice(term);

    freq[el]--;
    cout << el << " ";

    rec(level + 1, rem == 0 ? fact[curr_n - 1] : rem);

    freq[el]++;
}

void solve() {    
    cin >> n >> k;
    fact[0] = 1;
    for (int num = 1; num <= n; num++) {
        freq[num] = 1;
        fact[num] = num * fact[num - 1];
    }

    rec(0, k);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}