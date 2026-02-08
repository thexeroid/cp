#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;
using ull = unsigned long long;

ui N;
ui arr[100000];

ui m(ull num) {
    ui div = 1e9 + 7;
    return (ui)(num % div);
}

/*
For integers even in worst case __buitin_popcount gives like 32 in case of numbers 0 and -1 then too, 32 * 2 works it's just 64 so, it won't overflow by itself.
After every meaningful addition which is ans + (num upto 64), I take mod anyway so, it will always be in range.

Basically, the question is asking for all possible pairs that means every pair (x, y) is counted twice, once as (x, y) and another as (y, x) though the contribution would be same. So, I counted it once only for all pairs since, every pair would have a duplicate pair contributing the same amount so, I just did 2 * ans at the end.
Also, (x, x) will contribute to nothing so, I escaped it as also, it will not be counted twice too because it contributes 0 and 0 * 2 = 0
*/
void brute_force() {
    ull ans = 0;
    for (ui i = 0; i < N; i++) {
        for (ui j = i + 1; j < N; j++) {
            ui pair_xor = arr[i] ^ arr[j];
            ans = m(ans + (__builtin_popcount(pair_xor) << 1));
        }
    }    

    cout << ans << endl;
}

/*
Here I just used contribution technique since what is asked is essentially sum of distinct bits in xor of all possible pairs. 
Also, xor is bitwise, independent of other bit and distinct bit at every position is independent of other bits so, we can do it this way I believe. 

Kinda weird though a little.
*/
void optimized() {
    ui ans = 0;

    for (ui pos = 0; pos < 32; pos++) {
        ui cnt_set = 0;
        for (ui i = 0; i < N; i++) {
            ui num = arr[i];

            cnt_set += (num >> pos) & 1;
        }
        ui cnt_unset = N - cnt_set;
        
        ull contrib = m(2ULL * cnt_set * cnt_unset);
        ans = m(ans + contrib);
    }

    cout << ans << endl;
}

void solve() {
    cin >> N;
    for (ui i = 0; i < N; i++) cin >> arr[i];

    // brute_force();
    optimized();
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