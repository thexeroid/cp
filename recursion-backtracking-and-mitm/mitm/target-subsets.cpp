#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

vector<int> generate(vector<int> &arr) {
    int size = arr.size();
    vector<int> ans;
    for (int mask = 0; mask < (1 << size); mask++) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }

        ans.push_back(sum);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int N, X;
    cin >> N >> X;

    vector<int> seg[2];
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        seg[i&1].push_back(num);
    }

    vector<int> sum_part1 = generate(seg[0]);
    vector<int> sum_part2 = generate(seg[1]);

    int cnt = 0;
    for (int i = 0; i < sum_part1.size(); i++) {
        cnt += upper_bound(sum_part2.begin(), sum_part2.end(), X - sum_part1[i]) - sum_part2.begin();
    }

    print(cnt);
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