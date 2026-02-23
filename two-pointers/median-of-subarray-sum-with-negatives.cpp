#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long
#define endl "\n"

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int N;
int arr[100001];
int PS[100001];

bool check(int X, int K) {
    int cnt = 0;
    ordered_set os;
    
    int id = 0;
    os.insert({0, id++});
    for (int r = 0; r < N; r++) {
        cnt += os.size() - os.order_of_key({PS[r] - X, LLONG_MIN});
        os.insert({PS[r], id++});
    }

    return cnt >= K; 
}

void solve() {
    cin >> N;

    int ts = 0;
    int mn = INT_MAX;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        PS[i] = (i > 0 ? PS[i - 1] : 0) + num;
        ts += num;
        mn = min(mn, num);
    }
    
    int M = N * (N + 1) / 2;
    int K = (M + 1) / 2;

    int ans = -1;
    int s = mn, e = ts;
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (check(mid, K)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
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