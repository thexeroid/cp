#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, M, K;
int *A = new int[1000001];
int *B = new int[1000001];

bool check(int mid) {
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        cnt += upper_bound(B, B + M, mid - A[i]) - B;
        if (cnt >= K) return true;
    }

    return false;
}

bool check_tp(int mid) {
    int cnt = 0;
    int i = 0, j = M - 1;
    while (i < N && j >= 0) {
        if (A[i] + B[j] > mid) {
            j--;
        } else {
            cnt += (j + 1);
            if (cnt >= K) return true;
            i++;
        }
    }

    return false;
}

void solve() {    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];

    if (N > M) {
        swap(A, B);
        swap(N, M);
    }

    sort(A, A + N);
    sort(B, B + M);

    int ans = -1;

    int l = 0, r = 2e4;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check_tp(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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

    delete[] A;
    delete[] B;

    return 0;
}