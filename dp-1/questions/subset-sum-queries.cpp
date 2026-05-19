#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
int rec(vector<int> &arr, int level, int target) {
    // pruning
    if (target < 0) return 0;

    // base case
    if (target == 0) return 1;
    if (level == arr.size()) return 0;

    // memo return
    if (dp[level][target] != -1) return dp[level][target];

    // transition
    int ans = max(
        rec(arr, level + 1, target - arr[level]), 
        rec(arr, level + 1, target)
    );

    // save and return
    return dp[level][target] = ans;
}

vector<int> res;
void generate(vector<int> &arr, int level, int target) {
    if (level == arr.size()) return;
    
    int take = rec(arr, level + 1, target - arr[level]);
    
    if (take == 1) {
        res.push_back(level);
        generate(arr, level + 1, target - arr[level]);
    } else {
        int donttake = rec(arr, level + 1, target);

        if (donttake == 1) {
            generate(arr, level + 1, target);
        }
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    memset(dp, -1, sizeof(dp));

    vector<vector<int>> ans; 
    
    for (int &q: queries) {
        if (rec(arr, 0, q)) {
            res.clear();
            generate(arr, 0, q);
            ans.push_back(res);
        } else {
            ans.push_back({-1});
        }
    }

    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        long long sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}