#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

void method1 (ui N) {
    ui ans = 0;
    for (ui i = 0; i < N; i++) {
        ui num;
        cin >> num;

        ui cnt = (i + 1u) * (N - i);
        if (cnt % 2) ans ^= num;
    }

    cout << (int)ans << endl;
}

/*
The second method is just a corollary from the first method.
We notice that across all subarrays, an element at index i occurs,
(i + 1) * (N - i) times.

Drawing the case table

N     i     (i+1)     (N-i)     (i+1)*(N-i)
O     O       E         E            E
O     E       O         O            O
E     O       E         O            E
E     E       O         E            E

For N = even,
both elements at odd and even indexes occur an even number of time across all subarrays. So, when N is even the ans is 0.

For N = odd,
the element at odd indexes occur even number of times across all subarrays. So, xor of them is 0. So, only interested case left is 
when elements are at even indexes then,
Each element occurs odd number of time across all subarrays.
By this way, the ans becomes xor of all elements at even indices.

*/

void method2(ui N) {
    ui ans = 0;

    if (N % 2)
        for (ui i = 0; i < N; i++) {
            ui num;
            cin >> num;

            if (i % 2 == 0) ans ^= num;
        }

    cout << (int)ans << endl;
}

ui N;
void solve() {
    cin >> N;

    method1(N);
    // method2(N);
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