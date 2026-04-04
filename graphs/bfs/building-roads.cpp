#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n, m;
vector<int> adj[100001];
int visited[100001];

void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &neigh: adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int cnt_ccomp = 0;
    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            cnt_ccomp++;
            bfs(node);
        }
    }

    print(cnt_ccomp - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}