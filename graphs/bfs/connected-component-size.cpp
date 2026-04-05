#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int N, M;
vector<vector<int>> mat;
vector<vector<int>> comp_name;
vector<int> comp_size;

void init() {
    cin >> N >> M;

    mat.assign(N, vector<int>(M, 0));
    comp_name.assign(N, vector<int>(M, 0));
    comp_size = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
}

bool is_visited(int x, int y) {
    return comp_name[x][y];
}

bool is_valid(int x, int y) {
    return (
        0 <= x && x < N && 0 <= y && y < M &&
        mat[x][y] == 0
    );
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, int comp_num) {
    queue<pair<int, int>> q;
    
    q.push({x, y});
    comp_name[x][y] = comp_num;
    if (comp_size.size() <= comp_num) comp_size.push_back(0);
    comp_size[comp_num]++;

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = top.first + dx[i], ny = top.second + dy[i];

            if (is_valid(nx, ny) && !is_visited(nx, ny)) {
                q.push({nx, ny});
                comp_name[nx][ny] = comp_num;
                comp_size[comp_num]++;
            }
        }
    }
}

void solve() {
    init();

    int curr_comp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (is_valid(i, j) && !is_visited(i, j)) {
                bfs(i, j, ++curr_comp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int curr = mat[i][j];
            int corr_comp = comp_name[i][j];

            if (is_valid(i, j) && comp_size[corr_comp] > 1) {
                mat[i][j] = comp_size[corr_comp];
            }

            cout << mat[i][j] << sp;
        }

        cout << nl;
    }
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