/*
Property:
Even length palindromes are always divisible by 11. Thus, they are not prime except 11.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

// Globals
int a, b;
int pow_10[11];
int curr_num;

// Init
void global_init() {
    int val = 1;
    for (int exp = 0; exp <= 10; exp++) {
        pow_10[exp] = val;
        val *= 10;
    }
}

// Helpers
int cnt_digits(int num) {
    int cp_num = num;
    
    int ans = 0;
    while (cp_num) {
        ans++;
        cp_num /= 10; 
    }

    num == 0 && ans++;

    return ans;
}

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

// Check
bool check(int level, int choice, int n) {
    if (level == 0) {
        if (n > 1) {
            if (choice % 2 == 0 || choice == 5) return false;
        }
    }

    return true;
}

// Recursion func
int rec(int level, int n) {
    if (curr_num > b) return 0;

    if (level == (n + 1) / 2) {
        return a <= curr_num && is_prime(curr_num);
    }
    
    int ans = 0;
    for (int ch = 0; ch <= 9; ch++) {
        if (check(level, ch, n)) {
            int delta = ch * (pow_10[level] + pow_10[n - 1 - level]);
            if (level == n - 1 - level) delta /= 2;

            curr_num += delta;
            ans += rec(level + 1, n);
            curr_num -= delta;
        }
    }
    
    return ans;
}

void solve() {
    cin >> a >> b;
    
    int fl = cnt_digits(a), ll = cnt_digits(b);
    if (fl % 2 == 0) fl++;
    if (ll % 2 == 0) ll--;

    int ans = 0;
    for (int len = fl; len <= ll; len+=2) {
        ans += rec(0, len);
    }

    if (a <= 11 && 11 <= b) ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    global_init();

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}