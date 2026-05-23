#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
vector<int> dist;
vector<int> parent;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    dist.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    for (int edge = 1; edge < n; edge++) {
        int from, to; 
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

void dfs(int node, int par, int level) {
    dist[node] = level;
    parent[node] = par;

    for (auto neigh: tree[node]) {
        if (neigh != par) {
            dfs(neigh, node, level + 1);
        }
    }
}

void solve() {
    input();

    dfs(1, 0, 0);
    
    int farthest = 0;
    for (int node = 1; node <= n; node++) {
        if (dist[node] >= dist[farthest]) farthest = node;
    }

    dfs(farthest, 0, 0);
    
    for (int node = 1; node <= n; node++) {
        if (dist[node] >= dist[farthest]) farthest = node;
    }

    int diameter = dist[farthest];
    
    int ans = farthest;
    if (diameter % 2 == 0) {
        for (int i = 0; i * 2 < diameter; i++) ans = parent[ans];
    } else ans = -1;

    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}