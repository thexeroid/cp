/*
The minimum xor pair will be among the adjacent elements.
Like, it is provable by assuming that the minimum xor pair lies among non-adjacent elements and disproving the space.
Like, xor is dominated by the first bit where they differ
so, it becomes like let's assume p
so, it becomes 2^p <= (arr[i] ^ arr[j]) < 2^(p + 1), j > i + 1
thus, there will exist an element arr[i] < arr[k] < ... arr[j] where either arr[k] differs from arr[i] at MSB < p or arr[k] differs from arr[j] at MSB < p
thus, in both cases the 2 ^(p - 1)<= xor < 2^(p) so, the answer is less than 2^p which is the minimum value of space thus, space(2) is discarded.
*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

using ui = unsigned int;

int N;
ui arr[100000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr + N);
    ui ans = UINT_MAX;
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, arr[i] ^ arr[i + 1]);
    }

    cout << ans << endl;
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