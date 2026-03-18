#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const char nl = '\n';

int N;
string R, C;

char grid[5][5];
int rowmasks[5];
int colmasks[5];

char choices[] = {'A', 'B', 'C', '.'};

int cnt_set(int num) {
    int ans = 0;
    while (num) {
        ans++;
        num = num & (num - 1);
    }

    return ans;
}

bool check(char choice, int row, int col) {
    int fmask = (1 << 3) - 1;
    int rmask = rowmasks[row], cmask = colmasks[col];
    
    if (choice == '.') {
        int req_row_chs = 3 - cnt_set(rmask);
        int req_col_chs = 3 - cnt_set(cmask);

        int rem_col_cells = N - row - 1;
        int rem_row_cells = N - col - 1;

        if (rem_row_cells < req_row_chs || rem_col_cells < req_col_chs) return false;
        return true;
    }

    if (rmask == 0 && choice != R[row]) return false;
    if (cmask == 0 && choice != C[col]) return false;
    
    int bpos = choice - 'A';
    if (rmask & (1 << bpos)) return false;
    if (cmask & (1 << bpos)) return false; 
    
    // Simulate placing
    rmask |= (1 << bpos);
    cmask |= (1 << bpos);

    if (col == N - 1 && (rmask ^ fmask) != 0) return false;
    if (row == N - 1 && (cmask ^ fmask) != 0) return false;
    
    return true;
}

bool rec(int level) {
    if (level == N * N) {
        cout << "Yes" << nl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j];
            }
            cout << nl;
        }


        return true;
    }

    int row = level / N;
    int col = level % N;

    for (char ch: choices) {
        if (check(ch, row, col)) {
            int bpos = ch - 'A';
            
            if (ch != '.') {
                grid[row][col] = ch;
                rowmasks[row] |= (1 << bpos);
                colmasks[col] |= (1 << bpos);
            }

            bool res = rec(level + 1);

            if (ch != '.') {
                grid[row][col] = '.';
                rowmasks[row] &= ~(1 << bpos);
                colmasks[col] &= ~(1 << bpos);
            }

            if (res) return true;
        }
    }

    return false;
}

void solve() {
    cin >> N >> R >> C;

    if (!rec(0)) cout << "No" << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(grid, '.', sizeof(grid));  

    solve();

    return 0;
}