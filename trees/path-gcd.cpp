#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<int> val;
vector<vector<int>> tree;

vector<vector<int>> parent;
vector<int> depth;
vector<vector<int>> dp;

const int mx_bits = 20;

void input() {
    cin >> n;
    val.resize(n + 1);
    for (int node = 1; node <= n; node++) cin >> val[node];

    tree.assign(n + 1, {});
    for (int edge = 1; edge < n; edge++) {
        int from, to;
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    parent.assign(n + 1, vector<int>(mx_bits));
    depth.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(mx_bits));
}

void precompute(int node, int prev, int level) {
    parent[node][0] = prev;
    depth[node] = level;
    dp[node][0] = val[node];

    for (int exp = 1; exp < mx_bits; exp++) {
        dp[node][exp] = __gcd(dp[node][exp - 1], dp[parent[node][exp - 1]][exp - 1]);
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

    int ans = 0;
    int jump = depth[node1] - depth[node2];
    for (int exp = mx_bits - 1; exp >= 0; exp--) {
        if (jump & (1 << exp)) {
            ans = __gcd(ans, dp[node1][exp]);
            node1 = parent[node1][exp];
        }
    }

    if (node1 == node2) return __gcd(ans, val[node1]);

    for (int exp = mx_bits - 1; exp >= 0; exp--) {
        if (parent[node1][exp] != parent[node2][exp]) {
            ans = __gcd(ans, dp[node1][exp]);
            node1 = parent[node1][exp];
            ans = __gcd(ans, dp[node2][exp]);
            node2 = parent[node2][exp];
        }
    }

    ans = __gcd(ans, val[node1]);
    ans = __gcd(ans, val[node2]);

    return gcd(ans, val[parent[node1][0]]);
}

void solve() {
    input();
    precompute(1, 0, 0);

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;

        print(lca(x, y));
    }
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