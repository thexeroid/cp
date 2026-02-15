#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

int N;
int arr[100001];
int ans[5]{};
/*
To be computed:
1. sum(xor(pair)) for all pairs of form (arr[i], arr[j]); i < j
2. sum(xor(T)) for T in {list of all subsets of arr}
3. sum(and(pair)) for all pairs of form (arr[i], arr[j]); i < j
4. sum(and(T)) for T in {list of all subsets of arr}
*/

int binpow(int base, int exp, int mod) {
    int res = 1;
    while (exp) {
        if (exp % 2) res = (res * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

// Works when GCD(num, mod) = 1 & mod is prime
int inv(int num, int mod) {
    return binpow(num, mod - 2, mod);
}

void solve() {
    for (int op = 1; op < 5; op++) ans[op] = 0;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int pos = 0; pos < 31; pos++) {
        int cnt_set = 0, cnt_unset = 0;
        for (int i = 0; i < N; i++) {
            int num = arr[i];

            if ((num >> pos) & 1) cnt_set++;
            else cnt_unset++;
        }

        // Operation 1
        int cnt_set_xor_pair = (cnt_set * cnt_unset) % mod;
        int pos_contrib_op_one = (cnt_set_xor_pair * (1LL << pos)) % mod;
        ans[1] = (ans[1] + pos_contrib_op_one) % mod;

        // Operation 2
        int cnt_set_xor_subset = (cnt_set > 0 ? binpow(2, N - 1, mod) : 0);
        int pos_contrib_op_two = (cnt_set_xor_subset * (1LL << pos)) % mod;
        ans[2] = (ans[2] + pos_contrib_op_two) % mod;

        // Operation 3
        int cnt_set_and_pair = (((cnt_set * (cnt_set - 1)) % mod) * inv(2, mod)) % mod;
        int pos_contrib_op_three = (cnt_set_and_pair * (1LL << pos)) % mod;
        ans[3] = (ans[3] + pos_contrib_op_three) % mod;

        // Operation 4
        int cnt_set_and_subset = (binpow(2, cnt_set, mod) - 1) % mod;
        int pos_contrib_op_four = (cnt_set_and_subset * (1LL << pos)) % mod;
        ans[4] = (ans[4] + pos_contrib_op_four) % mod;
    }

    for (int op = 1; op < 5; op++) {
        cout << (ans[op] + mod) % mod << " ";
    }
    cout << endl;
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