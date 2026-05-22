// Way 1
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
vector<int> dist;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    dist.assign(n + 1, 0);

    for (int edge = 1; edge < n; edge++) {
        int from, to; 
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

void dfs(int node, int parent, int level) {
    dist[node] = level;

    for (auto neigh: tree[node]) {
        if (neigh != parent) {
            dfs(neigh, node, level + 1);
        }
    }
}

void solve() {
    input();

    dfs(1, 0, 0);
    
    int farthest = 0;
    for (int node = 1; node <= n; node++) {
        if (dist[node] > dist[farthest]) farthest = node;
    }

    dfs(farthest, 0, 0);
    
    for (int node = 1; node <= n; node++) {
        if (dist[node] > dist[farthest]) farthest = node;
    }

    print(dist[farthest]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// Way 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
vector<vector<int>> tree;
int diameter;

void input() {
    cin >> n;
    tree.assign(n + 1, {});
    diameter = 0;

    for (int edge = 1; edge < n; edge++) {
        int from, to; 
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
}

int dfs(int node, int parent) {
    int max1 = 0, max2 = 0;

    for (auto neigh: tree[node]) {
        if (neigh != parent) {
            int len = dfs(neigh, node);
            
            if (len >= max1) {
                max2 = max1;
                max1 = len;
            }
            else if (len >= max2) max2 = len;
        }
    }

    diameter = max(diameter, max1 + max2 + 1);
    return max1 + 1;
}

void solve() {
    input();

    dfs(1, 0);
    print(diameter - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}