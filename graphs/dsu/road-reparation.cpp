#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

class DSU {
    int n, components;
    vector<int> rep, rank;

public:
    DSU(int n): n(n), components(n), rep(n + 1), rank(n + 1, 1) {
        for (int i = 1; i <= n; i++) rep[i] = i;
    }

    int find(int node) {
        if (rep[node] == node) return node;

        return rep[node] = find(rep[node]);
    }

    bool merge(int node1, int node2) {
        int rep1 = find(node1), rep2 = find(node2);

        if (rep1 == rep2) return false;

        if (rank[rep1] < rank[rep2]) swap(rep1, rep2);

        rep[rep2] = rep1;
        rank[rep1] += rank[rep2];

        this->components--;

        return true;
    }

    int get_components() {
        return this->components;
    }

    int get_size(int node) {
        if (node < 1 || node > n) return 0;

        return this->rank[find(node)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> get<0>(edges[i]) >> get<1>(edges[i]) >> get<2>(edges[i]);
    }

    auto cmp = [](const auto &x, const auto &y) {
        return get<2>(x) < get<2>(y);
    };
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    int used = 0;
    
    ll ans = 0;

    for (int i = 0; i < m && used < n - 1; i++) {
        auto edge = edges[i];
        if (dsu.merge(get<0>(edge), get<1>(edge))) {
            ans += get<2>(edge);
            used++;
        }
    }

    if (dsu.get_components() == 1) {
        print(ans);
    } else print("IMPOSSIBLE");
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}