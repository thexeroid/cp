/*

Like the graph can be multigraph:
Ignore self loops in input only.
The multi edge doesn't interrupt cycle detection.

That's it.

*/

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

        if (from != to) adj[from].push_back(to);
    }
}

bool dfs(int node) {
    color_mp[node] = 1;

    for (int &neigh: adj[node]) {
        if (color_mp[neigh] == 0) {
            if (dfs(neigh)) return true;
        }
        
        if (color_mp[neigh] == 1) return true;
    }

    color_mp[node] = 2;

    return false;
}

void solve() {
    init();

    for (int node = 1; node <= n; node++) {
        if (!color_mp[node]) {
            if(dfs(node)) {
                print("Yes");
                return;
            }
        }
    }

    print("No");
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