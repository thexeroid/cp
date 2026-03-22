#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

int N;
int arr[100001];
int temp[100001];

ll merge(int s1, int e1, int s2, int e2) {
    ll ans = 0;
    int cpy_s1 = s1, cpy_e1 = e1, cpy_s2 = s2, cpy_e2 = e2;

    int k = 0;
    while (cpy_s1 <= cpy_e1 && cpy_s2 <= cpy_e2) {
        if (arr[cpy_s1] <= arr[cpy_s2]) {
            temp[k++] = arr[cpy_s1++];
        } else {
            ans += (cpy_e1 - cpy_s1 + 1);
            temp[k++] = arr[cpy_s2++];
        }
    }

    while (cpy_s1 <= cpy_e1) {
        temp[k++] = arr[cpy_s1++];
    }

    while (cpy_s2 <= cpy_e2) {
        temp[k++] = arr[cpy_s2++];
    }

    for (int i = s1; i < s1 + k; i++) {
        arr[i] = temp[i - s1];
    }

    return ans;
}

ll rec(int s, int e) {
    if (s >= e) {
        return 0;
    }

    int mid = s + (e - s + 1) / 2;
    
    ll ans = 0;
    ans += rec(s, mid - 1);
    ans += rec(mid, e);
    ans += merge(s, mid - 1, mid, e);

    return ans;
}

void solve() {    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    cout << rec(0, N - 1) << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}