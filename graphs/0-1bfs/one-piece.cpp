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
vector<vector<int>> mat;
vector<vector<int>> dist;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

state wind_dir[5] = {
    {0, 0}, // dummy
    {0, 1}, // 1 (R)
    {0, -1}, // 2 (L)
    {1, 0}, // 3 (D)
    {-1, 0} // 4 (U)
};

void init() {
    cin >> N >> M;
    mat.assign(N, vector<int>(M));
    dist.assign(N, vector<int>(M, INT_MAX));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
}

int bfs(state source) {
    deque<state> dq;
    dq.push_back(source);
    dist[source.F][source.S] = 0;

    while (!dq.empty()) {
        state curr = dq.front();
        dq.pop_front();

        int cx = curr.F, cy = curr.S;

        state wind = wind_dir[mat[cx][cy]];

        for (int i = 0; i < 4; i++) {
            // neighbour indices
            int nx = cx + dx[i], ny = cy + dy[i];

            // Early escape for out of bounds
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            // Cost to come to neighbour
            int cost = !(nx == cx + wind.F && ny == cy + wind.S);

            if (dist[nx][ny] > dist[cx][cy] + cost) {
                if (cost) dq.push_back({nx, ny});
                else dq.push_front({nx, ny});
                
                dist[nx][ny] = dist[cx][cy] + cost;
            }
        }
    }

    return dist[N - 1][M - 1];
}

void solve() {
    init();

    print(bfs({0, 0}));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}