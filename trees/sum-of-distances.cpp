#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
vector<int> size;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    size.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

int fill_size(int node, int parent) {
    int ans = 1;

    for (auto neigh: tree[node]) {
        if (neigh != parent) {
            ans += fill_size(neigh, node);
        }
    }

    return size[node] = ans;
}

ll dfs(int node, int parent) {
    ll ans = 1LL * size[node] * (n - size[node]);

    for (auto neigh: tree[node]) {
        if (neigh != parent) {
            ans += dfs(neigh, node);
        }
    }

    return ans;
}

void solve() {
    input();

    fill_size(1, 0);
    
    print(dfs(1, 0));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}