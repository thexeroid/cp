#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;

int ob, cb;
int curr_depth, max_depth;
string seq;

char braces[] = {'(', ')'};

bool check(char ch) {
    if (ch == ')') return ob > cb;
    return ob < n / 2;
}

void rec(int level) {
    if (max_depth > k) return;

    if (level == n) {
        if (max_depth == k) cout << seq << endl;
        return;
    }

    for (char ch: braces) {
        bool is_open = ch == '(';

        if (check(ch)) {
            seq.push_back(ch);
            int copy_md = max_depth;
            if (is_open) {
                ob++;
                curr_depth++;
                max_depth = max(max_depth, curr_depth);
            } else {
                cb++;
                curr_depth--;
            }

            rec(level + 1);

            seq.pop_back();
            if (is_open) {
                ob--;
                curr_depth--;
                max_depth = copy_md;
            } else {
                cb--;
                curr_depth++;
            }
        }
    }
}

void solve() {    
    cin >> n >> k;

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