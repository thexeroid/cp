class DSU {
    int n, components;
    vector<int> rep, rank;

public:
    DSU(int n): n(n), components(n), rep(n + 2), rank(n + 1, 1) {
        for (int i = 1; i <= n; i++) rep[i] = i;
    }

    int find(int node) {
        if (rep[node] == node) return node;

        return rep[node] = find(rep[node]);
    }

    void merge(int node1, int node2) {
        int rep1 = find(node1), rep2 = find(node2);

        if (rep1 == rep2) return;

        if (rank[rep1] < rank[rep2]) swap(rep1, rep2);

        rep[rep2] = rep1;
        rank[rep1] += rank[rep2];

        this->components--;
    }

    int get_components() {
        return this->components;
    }

    int get_size(int node) {
        if (node < 1 || node > n) return 0;

        return this->rank[node];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        DSU dsu(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;

                int cnode = i * n + j + 1;
                
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || !grid[nx][ny]) continue;

                    int nnode = nx * n + ny + 1;
                    dsu.merge(cnode, nnode); 
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                
                set<int> st;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || !grid[nx][ny]) continue;

                    int nnode = nx * n + ny + 1;
                    st.insert(dsu.find(nnode));
                }

                int size = 1;
                for (auto it: st) {
                    size += dsu.get_size(it);
                }

                ans = max(ans, size);
            }
        }

        if (!ans) ans = n * n;
        return ans;
    }
};