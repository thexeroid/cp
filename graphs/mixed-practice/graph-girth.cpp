#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

const int INF = INT_MAX;

int n, m;
vector<vector<int>> adj;
vector<int> dist;

bool init() {
    cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    dist.assign(n + 1, INF);

    bool self_cycle = 0;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        if (from == to) {
            self_cycle = 1;
            continue;
        }

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    return self_cycle;
}

int bfs(int node) {
    queue<int> q;

    dist[node] = 0;
    q.push(node);

    int mn_cycle_len = INT_MAX;
    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (auto &neigh: adj[curr]) {
            if (dist[neigh] == INF) {
                dist[neigh] = dist[curr] + 1;
                q.push(neigh);
            } else if (dist[curr] <= dist[neigh]) {
                mn_cycle_len = min(mn_cycle_len, dist[curr] + dist[neigh] + 1);
                if (dist[curr] == dist[neigh]) return mn_cycle_len;
            }
        }
    }

    return mn_cycle_len;
}

void solve() {    
    int ans = INF;

    if (init()) ans = 1;
    else {
        for (int node = 1; node <= n; node++) {
            dist.assign(n + 1, INF);

            ans = min(ans, bfs(node));
        }
    }

    print((ans != INF ? ans : -1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}