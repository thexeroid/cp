#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {    
    int N;
    string S;

    cin >> N >> S;

    int ans = 0;
    int K = 1;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int cnt_window_ch = 0;
        int pos_window_ch = -1;
        int tail = 0, head = -1;
        while (tail < N) {
            while (head + 1 < N && (S[head + 1] != ch || (S[head + 1] == ch && cnt_window_ch < K))) {
                head++;
                if (S[head] == ch) {
                    cnt_window_ch++;
                    pos_window_ch = head;
                }
            }

            if (cnt_window_ch == K) {
                ans += head - pos_window_ch + 1;
            }

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if (S[tail] == ch) {
                    cnt_window_ch--;
                    pos_window_ch = -1;
                }
                tail++;
            }
        }
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