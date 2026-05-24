#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    depth.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int from, to; 
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

void dfs(int node, int par, int level) {
    parent[node] = par;
    depth[node] = level;

    for (auto neigh: tree[node]) {
        if (neigh != par) {
            dfs(neigh, node, level + 1);
        }
    }
}

int cnt_nodes(int node, int par, int level, int target_level) {
    if (level == target_level) return 1;
    
    int ans = 0;
    for (auto neigh: tree[node]) {
        if (neigh != par) {
            ans += cnt_nodes(neigh, node, level + 1, target_level);
        }
    }

    return ans;
}

void solve() {
    input();

    // diameter
    dfs(1, 0, 0);
    
    int farthest = 1;
    for (int node = 1; node <= n; node++) {
        if (depth[node] > depth[farthest]) farthest = node;
    }

    dfs(farthest, 0, 0);
    for (int node = 1; node <= n; node++) {
        if (depth[node] > depth[farthest]) farthest = node;
    }

    int diameter = depth[farthest];

    if (!diameter) {
        print(1);
        return;
    }

    // center
    int center1 = farthest;
    for (int i = 0; i < diameter / 2; i++) {
        center1 = parent[center1];
    }

    int center2 = parent[center1];

    ll ans = 0;
    if ((diameter + 1) % 2) {
        // 1 center case
        ll acc = 0;

        for (auto neigh: tree[center1]) {
            ll temp = cnt_nodes(neigh, center1, 1, diameter / 2);

            ans += temp * acc;
            acc += temp;
        }
    } else {
        // 2 center case
        ans = (
            1LL * cnt_nodes(center1, center2, 0, diameter / 2) *
            cnt_nodes(center2, center1, 0, diameter / 2)
        );
    }

    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}