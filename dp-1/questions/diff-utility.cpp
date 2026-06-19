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
    int ans = 0;
    if (S[i] == T[j])
        ans = rec(i + 1, j + 1);
    else
        ans = 1 + min(rec(i + 1, j), rec(i, j + 1));

    // save and return
    return dp[i][j] = ans;
}

void solve()
{
    init();

    rec(0, 0);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (S[i] == T[j])
        {
            cout << S[i] << sp;
            i++;
            j++;
        }
        else
        {
            if (rec(i + 1, j) <= rec(i, j + 1))
            {
                cout << '-' << S[i] << sp;
                i++;
            }
            else
            {
                cout << '+' << T[j] << sp;
                j++;
            }
        }
    }

    while (i < n)
    {
        cout << '-' << S[i] << sp;
        i++;
    }

    while (j < m)
    {
        cout << '+' << T[j] << sp;
        j++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}