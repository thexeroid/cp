#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> depth;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    parent.assign(n + 1, vector<int>(20));
    depth.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

void precompute(int node, int par, int level) {
    parent[node][0] = par;
    depth[node] = level;

    for (int exp = 1; exp < 20; exp++) {
        parent[node][exp] = parent[parent[node][exp - 1]][exp - 1];
    }

    for (auto neigh: tree[node]) {
        if (neigh != par) {
            precompute(neigh, node, level + 1);
        }
    }
}

int lca(int node1, int node2) {
    if (depth[node1] < depth[node2]) {
        swap(node1, node2);
    }

    int jump = depth[node1] - depth[node2];
    for (int exp = 19; exp >= 0; exp--) {
        if (jump & (1 << exp)) {
            node1 = parent[node1][exp];
        }
    }

    if (node1 == node2) return node1;

    for (int exp = 19; exp >= 0; exp--) {
        if (parent[node1][exp] != parent[node2][exp]) {
            node1 = parent[node1][exp];
            node2 = parent[node2][exp];
        }
    }

    return parent[node1][0];
}

void solve() {
    input();

    precompute(1, 0, 0);

    int q; cin >> q;
    while (q--) {
        int x, y, z; cin >> x >> y >> z;

        int l = lca(x, y);
        int rx = lca(x, z);
        int ry = lca(y, z);

        int ans = l;
        if (rx == l) ans = ry;
        else if (ry == l) ans = rx;

        print(ans);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--)
        solve();

    return 0;
}