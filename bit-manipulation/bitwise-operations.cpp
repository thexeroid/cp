#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001]{};
int sets[20]{};

void reset() {
    for(int pos = 0; pos < 20; pos++) {
        sets[pos] = 0;
    }
}

void solve() {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int pos = 0; pos < 20; pos++) {
        int cnt_set = 0;
        for (int i = 0; i < N; i++) {
            int num = arr[i];

            if ((num >> pos) & 1) {
                cnt_set++;
            }
        }

        sets[pos] = cnt_set;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int maximized_num = 0;
        for (int pos = 0; pos < 20; pos++) {
            if (sets[pos]) {
                maximized_num |= (1LL << pos);
                sets[pos]--;
            }
        }

        ans += maximized_num * maximized_num;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        reset();
        solve();
    }

    return 0;
}