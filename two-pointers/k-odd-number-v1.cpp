#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K, D;
int arr[100001];
int PS[100001]{};

void solve() {    
    cin >> N >> K >> D;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        PS[i] = (i > 0 ? PS[i - 1] + num : num);
    }
    
    int ans = LLONG_MIN;

    int odd_count = 0;
    multiset<int> ms;
    ms.insert(0);

    int l = 0;
    for (int r = 0; r < N; r++) {
        if (abs(arr[r] % 2)) odd_count++;
        while (l <= r && (odd_count > K)) {
            if (abs(arr[l] % 2)) odd_count--;
            ms.erase(ms.find(l > 0 ? PS[l - 1] : 0));
            l++;
        }

        auto it = ms.lower_bound(PS[r] - D);
        if (it != ms.end()) {
            ans = max(ans, PS[r] - *it);
        }
        
        ms.insert(PS[r]);
    }

    cout << (ans == LLONG_MIN ? "IMPOSSIBLE" : to_string(ans)) << endl;
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