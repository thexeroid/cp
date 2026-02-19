#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N;
int arr[100001];

set<int> s;

void solve() {    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && !s.count(arr[head + 1])) {
            head++;
            s.insert(arr[head]);
        }

        ans = max(ans, head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            s.erase(arr[tail]);
            tail++;
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