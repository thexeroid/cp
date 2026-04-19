#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int N, K;
const int M = 10;

using state = pair<int, int>;
#define F first
#define S second

vector<vector<int>> mat;
vector<vector<int>> mp_node_comp;
vector<int> mp_comp_size;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void init() {
    cin >> N >> K;
    mat.assign(N, vector<int>(M, 0));
    mp_node_comp.assign(N, vector<int>(M, 0));
    mp_comp_size = { 0 };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;

            mat[i][j] = ch - '0';
        }
    }
}

void dfs(state node, int comp_name) {
    int cx = node.F, cy = node.S;

    mp_node_comp[cx][cy] = comp_name;
    mp_comp_size[comp_name]++;

    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || mat[nx][ny] != mat[cx][cy] || mp_node_comp[nx][ny]) continue;

        state neigh = {nx, ny};
        dfs(neigh, comp_name);
    }
}

int delete_valid_ccs() {
    int comp_name = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mp_node_comp[i][j] || mat[i][j] == 0) continue;

            state node = {i, j};
            
            mp_comp_size.push_back(0);
            dfs(node, ++comp_name);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int comp = mp_node_comp[i][j];
            if (comp && mp_comp_size[comp] >= K) {
                mat[i][j] = 0;
                ans = 1;
            } 
        }
    }

    return ans;
}

void apply_gravity() {
    for (int j = 0; j < M; j++) {
        int write = N - 1;
        
        for (int i = N - 1; i >= 0; i--) {
            if (mat[i][j] > 0) {
                mat[write][j] = mat[i][j];
                write--;
            }
        }

        while (write >= 0) {
            mat[write][j] = 0;
            write--;
        }
    }
}

void solve() {
    init();

    while (true) {
        mp_node_comp.assign(N, vector<int>(M, 0));
        mp_comp_size = { 0 };

        int any_deleted = delete_valid_ccs();
        if (!any_deleted) break;

        apply_gravity();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mat[i][j];
        }
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}