#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

#define F first
#define S second
using state = pair<int, int>;

int N;
vector<vector<char>> mat;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool is_bounded(state node) {
    auto [x, y] = node;
    
    return 0 <= x && x < N && 0 <= y && y < N;
}

void set_visited(state node) {
    if(is_bounded(node)) mat[node.F][node.S] = '*';
}

bool get_visited(state node) {
    return is_bounded(node) && mat[node.F][node.S] == '*';
}

void init() {
    cin >> N;
    mat.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
}

pair<int, int> bfs(state node) {
    queue<state> q;
    mat[node.F][node.S] = '*';
    q.push(node);

    int area = 0;
    int perimeter = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            state neigh = {nx, ny};


            if (!is_bounded(neigh) || mat[nx][ny] == '.') {
                perimeter++;
                continue;
            }

            if (get_visited(neigh)) continue;

            set_visited(neigh);
            q.push(neigh);
        }
    }

    return {area, perimeter};
}

void solve() {
    init();

    int area = 0;
    int perimeter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!get_visited({i, j}) && mat[i][j] == '#') {
                auto [la, lp] = bfs({i, j});

                if (la > area) {
                    area = la;
                    perimeter = lp;
                } else if (la == area) perimeter = min(perimeter, lp);
            }
        }
    }

    print(area << sp << perimeter);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}