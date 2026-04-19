#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using state = pair<int, int>;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl
#define F first
#define S second

int N, M;
vector<vector<state>> adj;
vector<int> dist;

void init() {
    cin >> N >> M;
    adj.assign(N + 1, vector<state>());
    dist.assign(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        if (from == to) {
            continue;
        }

        adj[from].push_back({to, 0});
        adj[to].push_back({from, 1});
    }
}

int bfs(int source) {
    deque<int> dq;
    dq.push_back(source);
    dist[source] = 0;

    while (!dq.empty()) {
        int curr = dq.front(); 
        dq.pop_front();

        for (auto &it: adj[curr]) {
            int neigh = it.F, neigh_weigh = it.S;

            if (dist[neigh] > dist[curr] + neigh_weigh) {

                if (neigh_weigh) dq.push_back(neigh);
                else dq.push_front(neigh);

                dist[neigh] = dist[curr] + neigh_weigh;
            }
        }
    }

    return (dist[N] != INT_MAX ? dist[N] : -1);
}

void solve() {
    init();

    print(bfs(1));
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