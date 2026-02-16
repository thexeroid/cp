#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, X;
int arr[100001];
void solve() {    
    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    for (int pos = 29; pos >= 0; pos--) {
        vector<int> ps_cnds;
        for (int i = 0; i < N; i++) {
            int num = arr[i];
            if ((num >> pos) & 1) ps_cnds.push_back(num);
        }

        int new_N = ps_cnds.size();
        if (new_N >= X) {
            ans |= (1LL << pos);
            
            N = new_N;
            for (int i = 0; i < new_N; i++) arr[i] = ps_cnds[i];
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