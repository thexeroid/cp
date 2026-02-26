#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
bool arr[100001];

// Binary Search: Solution 1
bool check(int L) {
    int zeroes = 0;
    
    int tail = 0, head = -1;
    while (head < N) {
        while (head + 1 < N && (arr[head + 1] == 1 || zeroes < K)) {
            head++;
            if (arr[head] == 0) zeroes++;
        }

        if (head - tail + 1 >= L) return true;

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            if (arr[tail] == 0) zeroes--;
            tail++;
        }
    }

    return false;
}

void solve() {    
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    int l = 1, r = N;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

// Two Pointer: Solution 2
void solve_two_pointer() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int zeroes = 0;
    int ans = 0;

    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (arr[head + 1] == 1 || zeroes < K)) {
            head++;
            if (arr[head] == 0) zeroes++;
        }

        ans = max(ans, head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1; 
        } else {
            if (arr[tail] == 0) zeroes--;
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
        // solve();
        solve_two_pointer();
    }

    return 0;
}