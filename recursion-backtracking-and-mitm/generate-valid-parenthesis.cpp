#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;

string seq;
int ob, cb; 

bool check(int level, char ch) {
    if (ch == ')') return ob > cb;
    
    return ob < n / 2;
}

void rec(int level) {
    if (level == n) {
        cout << seq << endl;
        return;
    }

    char choices[] = {'(', ')'}; 
    for (auto ch: choices) {
        if (check(level, ch)) {
            bool open = ch == '(';
            
            seq.push_back(ch);
            open ? ob++ : cb++;

            rec(level + 1);

            seq.pop_back();
            open ? ob-- : cb--;
        }
    }
}

void solve() {
    cin >> n;

    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}