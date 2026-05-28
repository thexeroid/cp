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

vector<ll> PS;

const int mx_bits = 20;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    
    for (int edge = 1; edge < n; edge++) {
        int from, to;
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    parent.assign(n + 1, vector<int>(mx_bits, 0));
    depth.assign(n + 1, 0);

    PS.assign(n + 1, 0);
}

void precompute(int node, int prev, int level) {
    depth[node] = level;
    parent[node][0] = prev;

    for (int exp = 1; exp < mx_bits; exp++) {
        parent[node][exp] = parent[parent[node][exp - 1]][exp - 1];
    }

    for (auto neigh: tree[node]) {
        if (neigh != prev) {
            precompute(neigh, node, level + 1);
        }
    }
}

int lca(int node1, int node2) {
    if (depth[node1] < depth[node2]) swap(node1, node2);

    int diff = depth[node1] - depth[node2];
    for (int exp = mx_bits - 1; exp >= 0; exp--) {
        if (diff & (1 << exp)) {
            node1 = parent[node1][exp];
        }
    }

    if (node1 == node2) return node1;

    for (int exp = mx_bits - 1; exp >= 0; exp--) {
        if (parent[node1][exp] != parent[node2][exp]) {
            node1 = parent[node1][exp];
            node2 = parent[node2][exp];
        }
    }

    return parent[node1][0];
}

void finalize(int node, int prev) {
    for (auto neigh: tree[node]) {
        if (neigh != prev) {
            finalize(neigh, node);
        }
    }

    PS[prev] += PS[node];
}

void solve() {
    input();
    precompute(1, 0, 0);

    int q; cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        PS[x] += z;
        PS[y] += z;
        
        int local_lca = lca(x, y);

        PS[local_lca] -= z;
        PS[parent[local_lca][0]] -= z;
    }

    finalize(1, 0);

    for (int node = 1; node <= n; node++) cout << PS[node] << sp;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) 
        solve();

    return 0;
}