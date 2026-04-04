#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

vector<int> adj[1000001];
int visited[1000001];

void dfs(int node) {
    visited[node] = 1;

    for (int &neigh: adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    pair<char, int> prev[m], curr[m];

    int curr_node = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            
            auto [prow_ch, prow_node] = prev[j];
            auto [pcol_ch, pcol_node] = j > 0 ? curr[j - 1] : pair<char, int>{' ', 0};
            curr[j] = {ch, 0};

            if (ch == '.') {
                curr[j].second = ++curr_node;

                if (prow_ch == '.') {
                    adj[curr_node].push_back(prow_node);
                    adj[prow_node].push_back(curr_node);
                }

                if (pcol_ch == '.') {
                    adj[curr_node].push_back(pcol_node);
                    adj[pcol_node].push_back(curr_node);
                }
            }
        }

        copy(curr, curr + m, prev);
    }

    int curr_comp = 0;
    for (int nd = 1; nd <= curr_node; nd++) {
        if (!visited[nd]) {
            dfs(nd);
            curr_comp++;
        }
    }

    print(curr_comp);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}