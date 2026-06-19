#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

string S, T;
int n, m;
vector<vector<int>> dp;

void init()
{
    cin >> S >> T;
    n = S.size();
    m = T.size();

    dp.assign(n + 1, vector<int>(m + 1, -1));
}

int rec(int i, int j)
{
    // pruning
    // base case
    if (i >= n)
        return m - j;
    if (j >= m)
        return n - i;

    // cache check
    if (dp[i][j] != -1)
        return dp[i][j];

    // transitions
    int ans = min({1 + rec(i, j + 1),
                   1 + rec(i + 1, j),
                   (S[i] != T[j]) + rec(i + 1, j + 1)});

    // save and return
    return dp[i][j] = ans;
}

void solve()
{
    init();

    print(rec(0, 0));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}