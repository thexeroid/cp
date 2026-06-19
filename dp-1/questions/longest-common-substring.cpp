#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

using P = pair<int, int>;
#define F first
#define S second

string S1, S2;
int n, m;
vector<vector<int>> dp;

void input()
{
    cin >> S1 >> S2;
    n = S1.size();
    m = S2.size();

    dp.assign(n + 1, vector<int>(m + 1, -1));
}

int rec(int i, int j)
{
    // pruning
    // base case
    if (i >= n || j >= m)
        return 0;
    if (S1[i] != S2[j])
        return 0;

    // cache check
    if (dp[i][j] != -1)
        return dp[i][j];

    // transitions
    int ans = 1 + rec(i + 1, j + 1);

    // save and return
    return dp[i][j] = ans;
}

void solve()
{
    input();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j));
        }
    }

    print(ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}