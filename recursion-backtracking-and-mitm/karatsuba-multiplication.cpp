/*
The TC
The SC
Number overflow? Why? How much?
Will it work for odd?
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

#define int long long

void rec(int *a, int *b, int *res, int n) {
    if (n == 1) {
        res[0] = a[0] * b[0];
        return;
    }

    int exp = (n + 1) / 2;
    int exp1 = n - exp;

    int p1[2 * exp - 1] = {0}; // a0 * b0
    int p2[2 * exp1 - 1] = {0}; // a1 * b1

    int tA[exp], tB[exp]; // (a0 + b0), (a1 + b1)
    int p3[2 * exp - 1] = {0}; // (a0 + b0) * (a1 + b1)

    int *a0 = a;
    int *a1 = a + exp;

    int *b0 = b;
    int *b1 = b + exp;

    rec(a0, b0, p1, exp);
    rec(a1, b1, p2, exp1);

    for (int i = 0; i < exp; i++) {
        tA[i] = a0[i] + (i + exp < n ? a1[i] : 0);
        tB[i] = b0[i] + (i + exp < n ? b1[i] : 0);
    }

    rec(tA, tB, p3, exp);

    // Subtracting p1 and p2 from p3
    for (int i = 0; i < 2 * exp - 1; i++) {
        p3[i] -= p1[i];
        if (i < 2 * exp1 - 1) p3[i] -= p2[i]; 
    }

    for (int i = 0; i < 2 * exp - 1; i++) {
        res[i] += p1[i];
        res[i + exp] += p3[i];
        if (i < 2 * exp1 - 1)
            res[i + 2 * exp] += p2[i];
    }
}

void solve() {
    int N;
    cin >> N;

    int len = N + 1;

    int A[len];
    int B[len];
    int C[2 * N + 1] = {0};

    for (int i = 0; i < len; i++) cin >> A[i];
    for (int i = 0; i < len; i++) cin >> B[i];

    rec(A, B, C, len);

    for (int i = 0; i < 2 * N + 1; i++) {
        cout << C[i] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}