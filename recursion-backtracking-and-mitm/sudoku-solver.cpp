/*
This makes pretty good use of 

x = NSE(x / y) * y + (x % y)

Mistakes made: Don't go on to like empty the board after we got a solution already.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int bs = 9;
const int cs = 3;

int board[bs][bs];
int rows[bs];
int cols[bs];
int grids[bs];
int LOG2[1001];

pair<int, int> get_coords(int level) {
    return {level / bs, level % bs};
}

void place(int x, int y, int ch) {
    rows[x] |= (1LL << ch);
    cols[y] |= (1LL << ch);

    int gx = x / cs, gy = y / cs;
    grids[gx * cs + gy] |= (1LL << ch);

    board[x][y] = ch;
}

void unplace(int x, int y, int ch) {
    rows[x] ^= (1LL << ch);
    cols[y] ^= (1LL << ch);

    int gx = x / cs, gy = y / cs;
    grids[gx * cs + gy] ^= (1LL << ch);

    board[x][y] = 0;
}

// bool check(int level, int ch) {
//     auto [x, y] = get_coords(level);
//     int gx = x / cs, gy = y / cs;

//     if (rows[x] & (1LL << ch) || (cols[y] & (1LL << ch)) || (grids[gx * cs + gy] & (1LL << ch))) return false;

//     return true;
// }

int get_choices(int row, int col) {
    int mask_used = rows[row] | cols[col] | grids[(row / cs) * cs + (col / cs)];
    int mask_unused = ((1 << (bs + 1)) - 2) ^ mask_used;

    return mask_unused;
}

void rec(int level) {
    if (level == bs * bs) {
        for (int i = 0; i < bs; i++) {
            for (int j = 0; j < bs; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    auto [x, y] = get_coords(level);
    if (board[x][y] == 0) {
        // for (int ch = 1; ch <= 9; ch++) {
        //     if (check(level, ch)) {
        //         place(x, y, ch);
        //         rec(level + 1);
        //         unplace(x, y, ch);
        //     }
        // }

        int choices_mask = get_choices(x, y);
        while (choices_mask) {
            int last_set = choices_mask ^ (choices_mask & (choices_mask - 1));
            int ch = LOG2[last_set];

            place(x, y, ch);
            rec(level + 1);
            unplace(x, y, ch);

            choices_mask &= (choices_mask - 1);
        }
    } else rec(level + 1);
}

void solve() {
    for (int exp = 0; exp <= bs; exp++) {
        LOG2[(1 << exp)] = exp;
    }

    for (int i = 0; i < bs; i++) {
        for (int j = 0; j < bs; j++) {
            char ch;
            cin >> ch;

            int digit = ch - '0';
            if (0 <= digit && digit <= 9) {
                place(i, j, digit);
            }
        }
    }

    rec(0);
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