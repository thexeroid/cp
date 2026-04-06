#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

class Solution {
    using state = tuple<int, int, int>;
    const int INF = 1e9;

    int n, m, k;
    vector<vector<int>>* grid; // SC: n * m
    vector<vector<pair<int, int>>> dist; // SC: n * m

    void init(vector<vector<int>> &grid, int k) { // TC: n * m
        this->grid = &grid;
        this->n = grid.size();
        this->m = grid[0].size();
        this->k = k;

        dist.assign(n, vector<pair<int, int>>(m, {INF, 0}));
    }

    int delta_x[4] = {-1, 1, 0, 0};
    int delta_y[4] = {0, 0, -1, 1};

public:
    int bfs(state source) { // TC: n * m * k, SC: n * m * k
        if (k >= n + m - 3) return n + m - 2;
        
        auto &g = *grid;

        auto [sx, sy, sk] = source;

        queue<state> q;
        dist[sx][sy] = {0, sk};
        q.push(source);

        while (!q.empty()) {
            auto [cx, cy, ck] = q.front();
            q.pop();

            if (cx == n - 1 && cy == m - 1) return dist[cx][cy].F;

            for (int i = 0; i < 4; i++) {
                int nx = cx + delta_x[i];
                int ny = cy + delta_y[i];

                if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;

                int nk = ck - g[nx][ny];
                state neigh = {nx, ny, nk};

                if (nk < 0 || (dist[nx][ny].F != INF && nk <= dist[nx][ny].S)) continue;

                dist[nx][ny] = {dist[cx][cy].F + 1, nk};
                q.push(neigh);
            }
        }

        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        init(grid, k);

        state source = {0, 0, k};

        return bfs(source);
    }
};