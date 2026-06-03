/*

1 2 3
4 5 6
7 8 9


Mistakes: 
- Forgot to call init()

Enhancements:
- Use the android pattern symmetry trick
- precompute mid points and keep points 0 for pairs with no mid point and keep used[0] = true to keep them trivially true.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
const int dim = 3;
bool used[dim * dim + 1];
int mid[dim * dim + 1][dim * dim + 1];

void init() {
    cin >> n;

    used[0] = true;

    mid[1][3] = mid[3][1] = 2;
    mid[4][6] = mid[6][4] = 5;
    mid[7][9] = mid[9][7] = 8;

    mid[1][7] = mid[7][1] = 4;
    mid[2][8] = mid[8][2] = 5;
    mid[3][9] = mid[9][3] = 6;

    mid[1][9] = mid[9][1] = 5;
    mid[3][7] = mid[7][3] = 5;
}

bool check(int level, int curr, int prev) {
    // start case
    if (!prev) return true;

    return !used[curr] && used[mid[prev][curr]];
}

int rec(int level, int prev) {
    // base case
    if (level == n) {
        return 1;
    }
    
    // choices
    int ans = 0;
    for (int ch = 1; ch <= dim * dim; ch++) {
        if (check(level, ch, prev)) {
            used[ch] = 1;
            ans += rec(level + 1, ch);
            used[ch] = 0; 
        }
    }

    return ans;
}

void solve() {
    init();
    
    vector<pair<int, int>> pairs = {
        {1, 4},
        {2, 4},
        {5, 1}
    };

    int ans = 0;
    for (auto &pair: pairs) {
        used[pair.first] = true;
        ans += pair.second * rec(1, pair.first);
        used[pair.first] = false;
    }

    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}