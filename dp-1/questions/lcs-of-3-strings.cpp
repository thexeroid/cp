#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

string s1, s2, s3;
int n, m, o;
int dp[101][101][101];

void input() {
    cin >> s1 >> s2 >> s3;

    n = s1.size();
    m = s2.size();
    o = s3.size();

    memset(dp, -1, sizeof(dp));
}

int rec(int i, int j, int k) {
    // pruning
    // base case
    if (i < 0 || j < 0 || k < 0) return 0;
    
    // cache check
    if (dp[i][j][k] != -1) return dp[i][j][k];
    
    // transitions
    int ans = 0;
    if (s1[i] == s2[j] && s2[j] == s3[k]) 
        ans = 1 + rec(i - 1, j - 1, k - 1); 
    else 
        ans = max({
            rec(i - 1, j, k),
            rec(i, j - 1, k),
            rec(i, j, k - 1)
        });

    // save and return
    return dp[i][j][k] = ans;
}

void solve() {
    input();

    print(rec(n - 1, m - 1, o - 1));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}