#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int A[10001];
int B[10001];

bool check(double mid) {
    priority_queue<double, vector<double>, greater<double>> pq;

    for (int i = 0; i < N; i++) {
        double C = A[i] - mid * B[i];
        pq.push(C);
        if (pq.size() > K) pq.pop();
    }

    double sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum >= 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    
    double ans = -1;
    double l = 0, r = 1e4;
    while (abs(r - l) >= 1e-9) {
        double mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
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