#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

/*
To find:
1. smallest x1 such that sigma(ai xor x1); i: l -> r is maximum
2. smallest x2 such that sigma(ai or x2); i: l -> r is maximum
3. smallest x3 such that sigma(ai and x3); i: l -> r is maximum
*/

void print(int val, bool newline=false, string label = "") {
    if (label.size()) cout << label << ": ";
    cout << val << "; ";
    if (newline) cout << endl;
}

int N;
int arr[100001];
int PS[31][100001]{};
void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int pos = 0; pos < 31; pos++) {
        for (int i = 0; i < N; i++) {
            int num = arr[i];

            PS[pos][i] = ((num >> pos) & 1);
            if (i > 0) PS[pos][i] += PS[pos][i - 1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--; R--;

        int range_size = (R - L + 1);

        int x1, x2, x3;
        x1 = x2 = x3 = 0;

        for (int pos = 0; pos < 31; pos++) {
            int cnt_sets = PS[pos][R] - (L > 0 ? PS[pos][L - 1] : 0);
            int cnt_unsets = range_size - cnt_sets;

            // 1. minimum x1 that gives maximum sigma(ai xor x1); i: l -> r
            if (cnt_sets < cnt_unsets) {
                x1 |= (1LL << pos);
            }

            // 2. minimum x2 that gives maximum sigma(ai or x2): i: l -> r
            if (cnt_unsets > 0) {
                x2 |= (1LL << pos);
            }

            // 3. minimum x3 that gives maximum sigma(ai and x3): i: l -> r
            if (cnt_sets > 0) {
                x3 |= (1LL << pos);
            }
        }

        cout << (x1 + x2 + x3) << endl;
    }

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