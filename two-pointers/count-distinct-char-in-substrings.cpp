#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {    
    int N;
    string S;
    cin >> N >> S;

    int ans = 13 * N * (N + 1);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int contrib = 0;

        int tail = 0, head = -1;
        while (tail < N) {
            while (head + 1 < N && S[head + 1] != ch) {
                head++;
            }

            contrib += (head - tail + 1);

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                tail++;
            }
        }

        ans -= contrib;
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