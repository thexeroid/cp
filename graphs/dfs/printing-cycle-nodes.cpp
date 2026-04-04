#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, m;
vector<int> adj[100001];

int visited[100001];
vector<int> nodes;

bool dfs(int node, int parent) {
    visited[node] = 1;
    nodes.push_back(node);

    for (auto &neigh: adj[node]) {
        if (!visited[neigh]) {
            if (dfs(neigh, node)) return true;
        } else if (neigh != parent) {
            bool flag = false;
            for (auto &nneigh: nodes) {
                if (nneigh == neigh) flag = true;
                if (!flag) continue;

                cout << nneigh << sp;
            }
            cout << nl;
            return true;
        }
    }

    nodes.pop_back();

    return false;
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            if (dfs(node, 0)) break; 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}