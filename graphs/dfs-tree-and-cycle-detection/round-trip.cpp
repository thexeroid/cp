#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;
const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> dist;

void init() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    dist.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

bool dfs(int node, int parent) {
    color[node] = 1;
    dist[node] = dist[parent] + 1;

    for (auto &neigh: adj[node]) {
        if (neigh == parent) continue;

        if (color[neigh] == 0) {
            if (dfs(neigh, node)) return true;
        } else if (color[neigh] == 1) {
            return (dist[node] - dist[neigh] + 1) >= 3;
        }
    }

    color[node] = 2;

    return false;
}

void solve() {
    init();

    for (int node = 1; node <= n; node++) {
        if (dist[node] == -1) {
            if (dfs(node, 0)) {
                print("YES");
                return;
            }
        }
    }

    print("NO");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}