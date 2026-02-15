/*

1<=Q<=1e5
1<=K<=1e9

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void log(string str, int num, bool newline = false) {
    cout << str << ": " << num << "; ";
    if (newline) cout << endl;
}

// From 0 to n
int cnt_set_bits_till_n(int n) {
    int ans = 0;
    for (int pos = 0; pos < 31; pos++) {
        int quot = (n + 1) >> (pos + 1);
        int rem = (n + 1) & ((1LL << (pos + 1)) - 1);
        int diff = rem - (1LL << pos);

        ans += quot * (1LL << pos);
        if (diff > 0) ans += diff;
        if (quot == 0) break;
    }

    return ans;
}

// From 0 to n
int cnt_total_bits_till_n(int n) {
    if (n == 0) return 1;
    int ans = 1;

    int MSB = 31 - __builtin_clz(n);
    for (int k = 0; k <= MSB; k++) {
        ans += (min(n, (1LL << (k + 1)) - 1) - (1LL << (k)) + 1) * (k + 1);
    }

    return ans;
}

bool check(int num, int K) {
    int set_bits = cnt_set_bits_till_n(num);
    return set_bits >= K;
}

void solve() {
    int Q;
    cin >> Q;

    while (Q--) {
        int K;
        cin >> K;
        
        int ans = -1;
        int low = 1, high = K;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, K)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans != -1) {      
            int idx = cnt_total_bits_till_n(ans - 1) - 1;
            int target = K - cnt_set_bits_till_n(ans - 1);
            int MSB = 31 - __builtin_clz(ans);
            for (int pos = MSB; pos >= 0 && target > 0; pos--) {
                if ((ans >> pos) & 1) {
                    target--;
                }

                idx++;
            }
            
            log("idx", idx, true);
        }
    }
}

void test() {
    cout << cnt_set_bits_till_n(7) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    // test();

    return 0;
}