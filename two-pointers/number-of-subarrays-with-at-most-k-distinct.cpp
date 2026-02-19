#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, K;
int arr[100001];
map<int, int> mp;

/*
Approach 2: using frequency array slightly faster than map since, Ai <= 10^6 we can directly have an array act as a map for us.

int freq[1000001]{};
int distinct_count = 0;

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];     


    int ans = 0;
    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (freq[arr[head + 1]] || distinct_count < K)) {
            head++;
            if (freq[arr[head]] == 0) distinct_count++;
            freq[arr[head]]++;            
        }

        ans += (head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0) distinct_count--;
            tail++;
        }
    }

    cout << ans << endl;
}

*/

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];     

    int ans = 0;
    int tail = 0, head = -1;
    while (tail < N) {
        while (head + 1 < N && (mp.count(arr[head + 1]) || mp.size() < K)) {
            head++;
            mp[arr[head]]++;
        }

        ans += (head - tail + 1);

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            mp[arr[tail]]--;
            if (mp[arr[tail]] == 0) {
                mp.erase(arr[tail]);
            }
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