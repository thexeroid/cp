#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl
#define F first
#define S second

using state = pair<int, int>;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
vector<vector<int>> mat;
vector<vector<int>> dist;

int cnt_uninfected = 0;
vector<state> infected;

void init() {
    cin >> n >> m;
    mat.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) cnt_uninfected++;
            if (mat[i][j] == 2) infected.push_back({i, j});
        }
    }
}

int bfs() {
    queue<state> q;
    for (int i = 0; i < infected.size(); i++) {
        state node = infected[i];
    
        dist[node.F][node.S] = 0;
        q.push(node);
    }

    int cnt_left = cnt_uninfected;
    int ans = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        ans = max(ans, dist[cx][cy]);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            
            cnt_left--;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    return cnt_left == 0 ? ans : -1;
}

void solve() {
    init();

    print(bfs());   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}