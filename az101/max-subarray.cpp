#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';


int N;
pair<int, int> arr[101];
int freq[101];

void init() {
    memset(freq, 0, sizeof(freq));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = {num, i};
    }
}

void solve() {
    init();
    input();

    for (int s = 0; s < N; s++) {
        int mx = s;

        for (int e = s; e < N; e++) {
            if (arr[e].first > arr[mx].first) {
                mx = e;
            }

            freq[mx]++;
        }
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        auto [el, old_idx] = arr[i];

        for (int j = 0; j < freq[old_idx]; j++) cout << el << ' ';
    }
    cout << nl;
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