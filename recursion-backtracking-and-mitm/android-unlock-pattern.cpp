#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int taken[10];

int gs = 3;
int init_prev_ch = 0;

pair<int, int> get_coords(int choice) {
    choice--;
    return {choice / gs, choice % gs};
}

bool check(int level, int pc, int cc) {
    if (taken[cc]) return false;
    if (pc == init_prev_ch) return true;

    auto [r1, c1] = get_coords(pc);
    auto [r2, c2] = get_coords(cc);

    int row_diff = abs(r1 - r2);
    int col_diff = abs(c1 - c2);

    bool ans = true;
    int mid_ch = (pc + cc) / 2;

    if (col_diff == 0) {
        if (row_diff == gs - 1) {
            if (!taken[mid_ch]) ans = false;
        }
    } else if (row_diff == 0) {
        if (col_diff == gs - 1) {
            if (!taken[mid_ch]) ans = false;
        }
    } else {
        if (row_diff == gs - 1 && col_diff == gs - 1) {
            if (!taken[mid_ch]) ans = false;
        }
    }

    return ans;
}

int rec(int level, int pc) {
    if (level == n) {
        return 1;
    }

    int ans = 0;
    for (int ch = 1; ch <= gs * gs; ch++) {
        if (check(level, pc, ch)) {
            taken[ch] = 1;
            ans += rec(level + 1, ch);
            taken[ch] = 0;
        }
    }

    return ans;
}

void solve() {    
    cin >> n;

    pair<int, int> ch_mul[] = {
        {1, 4},
        {2, 4},
        {5, 1}
    };

    int ans = 0;
    for (auto it: ch_mul) {
        auto [ch, multiple] = it;

        taken[ch] = 1;
        ans += multiple * rec(1, ch);
        taken[ch] = 0;
    }


    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}