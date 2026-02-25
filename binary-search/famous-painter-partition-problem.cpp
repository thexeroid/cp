#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int arr[100001];

int time(int dist) {
    int speed = 1;
    return dist / speed; 
}

bool check(int T) {
    int assigned_painters = 1;
    int acc = 0;
    for (int i = 0; i < N; i++) {
        if (acc + time(arr[i]) <= T) {
            acc += time(arr[i]);
        } else {
            assigned_painters++;
            acc = time(arr[i]);
        }
    }

    return assigned_painters <= K;
}

void solve() {    
    cin >> N >> K;

    int sum = 0;
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        sum += num;
        mx = max(mx, num);
    }

    int ans = -1;
    int s = time(mx), e = time(sum);
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (check(mid)) {
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