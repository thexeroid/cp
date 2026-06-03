/*

1 2 3
4 5 6
7 8 9


Mistakes: 
- Forgot to call init()

Enhancements:
- Use the android pattern symmetry trick
*/

/*v1*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
const int dim = 3;
bool used[dim * dim + 1];

void init() {
    cin >> n;
}

int get_mid(int curr, int prev) {    
    int rcurr = (curr - 1) / dim;
    int ccurr = (curr - 1) % dim;

    int rprev = (prev - 1) / dim;
    int cprev = (prev - 1) % dim;

    int rdist = abs(rcurr - rprev);
    int cdist = abs(ccurr - cprev);

    int mid = (curr + prev) / 2;

    if (
        ((rdist == dim - 1) && (cdist == dim - 1)) ||
        (!rdist && (cdist == dim - 1)) ||
        ((rdist == dim - 1) && !cdist)
    ) return mid;

    return -1;
}

bool check(int level, int curr, int prev) {
    // start case
    if (used[curr]) return false;
    if (!prev) return true;

    int mid = get_mid(curr, prev);
    if (mid != -1 && !used[mid]) return false;
    
    return true;
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