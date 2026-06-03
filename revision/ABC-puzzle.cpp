#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
string R, C;

vector<int> rows;
vector<int> cols;
vector<vector<char>> board;

void init() {
    cin >> n;
    cin >> R >> C;

    rows.assign(n, 0);
    cols.assign(n, 0);
    board.assign(n, vector<char>(n, '.'));
}

// A -> 0; B -> 1; C -> 2
bool check(int row, int col, char ch) {    
    int fmask = 0b111;
    int rmask = rows[row];
    int cmask = cols[col];
    
    if (ch == '.') {
        // Simulating skipping
        int row_letters_to_be_placed = 3 - __builtin_popcount(rmask);
        int col_letters_to_be_placed = 3 - __builtin_popcount(cmask);

        int rem_row_cells = n - 1 - col;
        int rem_col_cells = n - 1 - row;

        if (
            (rem_row_cells < row_letters_to_be_placed) ||
            (rem_col_cells < col_letters_to_be_placed)
        ) return false;

        return true;
    }
    
    int pos = ch - 'A';
    // Duplicate and first char check
    if (
        (rmask & (1 << pos)) ||
        (cmask & (1 << pos)) ||
        (!rmask && ch != R[row]) ||
        (!cmask && ch != C[col])
    ) return false;

    // Simulating placing
    if (row == n - 1) {
        cmask ^= (1 << pos);
        if (cmask != fmask) return false;
    }

    if (col == n - 1) {
        rmask ^= (1 << pos);
        if (rmask != fmask) return false;
    }

    return true;
}

bool rec(int level) {
    // base case
    if (level == n * n) {
        return true;
    }

    int row = level / n;
    int col = level % n;

    // choices
    for (char ch = 'A'; ch <= 'C'; ch++) {
        if (check(row, col, ch)) {
            int pos = ch - 'A';
            rows[row] |= (1 << pos);
            cols[col] |= (1 << pos);
            board[row][col] = ch;

            if(rec(level + 1)) return true;

            rows[row] &= ~(1 << pos);
            cols[col] &= ~(1 << pos);
            board[row][col] = '.';

        }
    }

    if (check(row, col, '.')) {
        if (rec(level + 1)) return true;
    }
    
    return false;
}

void solve() {
    init();

    if (rec(0)) {
        print("Yes");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
            }
            cout << nl;
        }
    } else print("No");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}