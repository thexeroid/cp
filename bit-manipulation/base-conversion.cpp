#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
bool digits[100];

int BASE = 2;
int NEW_BASE = 6;

bool zero() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += digits[i];
        if (sum > 0) return false;
    }

    return true;
}

int divide() {
    int carry = 0;

    for (int i = 0; i < N; i++) {
        int curr = carry * BASE + digits[i];
        digits[i] = curr / NEW_BASE;
        carry = curr % NEW_BASE;
    }

    int idx = 0;
    while (idx < N && digits[idx] == 0) idx++;
    for (int i = idx; i < N; i++) {
        digits[i - idx] = digits[i];
    }
    N -= idx;

    return carry;
}

void solve() {
    string S;
    cin >> S;
    
    N = S.size();

    for (int i = 0; i < N; i++) {
        digits[i] = S[i] - '0';
    }

    string ans = "";
    while (!zero()) {
        int rem = divide();
        ans += to_string(rem);
    }

    reverse(ans.begin(), ans.end());

    cout << (ans.size() > 0 ? ans : "0") << endl;
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