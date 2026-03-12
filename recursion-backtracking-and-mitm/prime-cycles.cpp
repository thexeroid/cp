#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int N;
int used[20];
const int start = 1;

const int prime_len = 40;
bool is_prime[prime_len];
void sieve() {
    fill(is_prime, is_prime + prime_len, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int num = 2; num <= prime_len / num; num++) {
        if (!is_prime[num]) continue;

        for (int mul = num * num; mul < prime_len; mul += num) {
            is_prime[mul] = false;
        }
    }
}

// bool is_prime(int num) {
//     if (num <= 1) return false;
//     if (num <= 3) return true;
//     if (num % 2 == 0 || num % 3 == 0) return false;

//     int fact = 5;
//     while (fact <= num / fact) {
//         if (num % fact == 0) return false;
//         if (num % (fact + 2) == 0) return false;
//         fact += 6;
//     }

//     return true;
// }

bool check(int level, int prev, int ch) {
    if (used[ch]) return false;

    return is_prime[prev + ch];
}

int rec(int level, int prev, int par) {
    if (level == N) {
        return is_prime[start + prev];
    }

    int ans = 0;
    for (int ch = 1 + par; ch <= N; ch+=2) {
        if (check(level, prev, ch)) {
            used[ch] = 1;
            ans += rec(level + 1, ch, 1 - par);
            used[ch] = 0;
        }
    }
    
    return ans;
}

void global_init() {
    sieve();
    used[start] = 1;
}

void solve() {
    cin >> N;
    int ans = 0;
    if (N % 2 == 0) ans = rec(1, start, start % 2 == 1);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    global_init();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}