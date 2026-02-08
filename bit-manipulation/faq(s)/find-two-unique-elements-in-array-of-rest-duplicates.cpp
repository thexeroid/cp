#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

int N;
ui arr[100000];

void solve() {
    cin >> N;
    ui xor_ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        xor_ans ^= arr[i];
    }
    
    ui lsb_num = xor_ans & (~(xor_ans - 1));

    ui num1 = 0;
    ui num2 = 0;

    for (int i = 0; i < N; i++) {
        if (lsb_num & arr[i]) num1 ^= arr[i];
        else num2 ^= arr[i]; 
    }

    int a = (int)num1;
    int b = (int)num2;

    cout << min(a, b) << ' ' << max(a, b) << endl;
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