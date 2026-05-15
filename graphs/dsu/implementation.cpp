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