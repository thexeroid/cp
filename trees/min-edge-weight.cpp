#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

class DSU {
    vector<int> rep;
    vector<int> size;

public:
    DSU(int n): rep(n + 1), size(n + 1, 1) {
        for (int node = 1; node <= n; node++) rep[node] = node;
    }

    int find(int node) {
        if (node == rep[node]) return node;

        return rep[node] = find(rep[node]);
    }

    ll merge(int node1, int node2) {
        int rep1 = find(node1);
        int rep2 = find(node2);

        if (rep1 == rep2) return 0;

        if (size[rep1] < size[rep2]) swap(rep1, rep2);

        ll ans = 1LL * size[rep1] * size[rep2];

        rep[rep2] = rep1;
        size[rep1] += size[rep2];

        return ans;
    }
};

struct Edge {
    int from, to, weight;
};


void solve() {
    int n;
    cin >> n;

    vector<Edge> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges[i] = {from, to, weight};
    }

    auto cmp = [](const auto &x, const auto &y) {
        return x.weight > y.weight;
    };

    sort(edges.begin(), edges.end(), cmp);

    // Creating DSU
    DSU dsu(n);

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        auto &edge = edges[i];

        ll cnt = dsu.merge(edge.from, edge.to);
        ans += cnt * edge.weight;
    }

    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}