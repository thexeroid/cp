#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

ll path[50];
ll n;

const ll bs = 7;
bool used[bs * bs];

// U, R, D, L
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};

ll get_idx(ll x, ll y) {
    return x * bs + y;
}

void init() {
    used[0] = 1;
}

bool check(ll x, ll y) {
    if (x < 0 || x >= bs || y < 0 || y >= bs || used[get_idx(x, y)]) return false;

    return true;
}

ll rec(ll level, ll x, ll y) {
    if (level == n) {
        return x == bs - 1 && y == 0;
    }
    
    if (
        (x == bs - 1 && y == 0 && level != n) ||
        (check(x+1,y) && check(x-1,y) && !check(x,y+1) && !check(x,y-1)) ||
        (check(x,y+1) && check(x,y-1) && !check(x+1,y) && !check(x-1,y))
    ) return 0;

    ll ans = 0;
    int curr_dir = path[level];
    if (curr_dir == -1) {
        for (ll i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];

            if (check(nx, ny)) {
                ll idx = get_idx(nx, ny);

                used[idx] = 1;
                ans += rec(level + 1, nx, ny);
                used[idx] = 0;
            }
        }
    } else {
        int nx = x + dx[curr_dir], ny = y + dy[curr_dir];

        if (check(nx, ny)) {
            ll idx = get_idx(nx, ny);

            used[idx] = 1;
            ans += rec(level + 1, nx, ny);
            used[idx] = 0;
        }
    }

    return ans;
}

void solve() { 
    string str;
    cin >> str;

    n = str.size();

    for (ll i = 0; i < n; i++) {
        ll val = -1;
        switch(str[i]) {
            case 'U': val = 0; break;
            case 'R': val = 1; break;
            case 'D': val = 2; break;
            case 'L': val = 3; break;
        }

        path[i] = val;
    }

    cout << rec(0, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}