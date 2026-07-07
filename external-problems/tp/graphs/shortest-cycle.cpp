/*
Key learning:
Don't add same edge multiple times. Use a set seen.
length of cycles is: dist[u] + dist[v] + 1
*/

#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

using ll = long long;

const ll INF = 1e12;

ll n;
vector<ll> nodes_val;

void init()
{
    cin >> n;
    nodes_val.resize(n + 1);
    for (ll node = 1; node <= n; node++)
        cin >> nodes_val[node];
}

ll bfs(vector<vector<ll>> &adj, ll node)
{
    vector<ll> dist(n + 1, INF);
    vector<ll> par(n + 1, 0);

    queue<ll> q;

    dist[node] = 0;
    par[node] = 0;
    q.push(node);

    ll ans = INF;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();

        for (auto &neigh : adj[curr])
        {
            if (dist[neigh] > dist[curr] + 1)
            {
                dist[neigh] = dist[curr] + 1;
                par[neigh] = curr;
                q.push(neigh);
            }
            else if (neigh != par[curr])
            {
                ans = min(ans, dist[curr] + dist[neigh] + 1);
            }
        }
    }

    return ans;
}

void solve()
{
    init();

    vector<vector<ll>> groups(60);

    for (ll pos = 0; pos < 60; pos++)
    {
        for (ll node = 1; node <= n; node++)
        {
            if (nodes_val[node] & (1LL << pos))
            {
                groups[pos].push_back(node);
                if (groups[pos].size() >= 3)
                {
                    cout << 3 << nl;
                    return;
                }
            }
        }
    }

    set<pair<ll, ll>> seen;
    vector<vector<ll>> adj(n + 1);
    for (auto &it : groups)
    {
        if (it.size() == 2)
        {
            ll from = it[0], to = it[1];
            if (from > to)
                swap(from, to);

            if (seen.count({from, to}))
                continue;

            seen.insert({from, to});
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
    }

    ll ans = INF;
    for (ll node = 1; node <= n; node++)
    {
        if (!adj[node].empty())
        {
            ans = min(ans, bfs(adj, node));
        }
    }

    if (ans == INF)
        ans = -1;
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}