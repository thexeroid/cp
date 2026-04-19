#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, m;
vector<vector<int>> adj;
vector<int> color_mp;

void init() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    color_mp.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

bool dfs(int node, int color) {
    color_mp[node] = color;
    
    for (auto &neigh: adj[node]) {
        if (color_mp[neigh] == color) return false;
        if (!color_mp[neigh] && !dfs(neigh, 3^color)) return false;
    }

    return true;
}

void solve() {
    init();

    for (int node = 1; node <= n; node++) {
        if (!color_mp[node]) {
            if (!dfs(node, 1)) {
                print("NO");
                return;
            }
        }
    }

    print((n > 1 ? "YES" : "NO"));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}