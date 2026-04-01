#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define pnt(x) cout << x << nl

class Solver {
    string S;

    int get_len(int l, int r) {
        int N = S.size();
        return max(0, min(r, N - 1) - l + 1);
    }

    void print_empty() {
        pnt("");
    }
    
public:
    Solver(string &str) {
        this->S = str;
    }

    void pop_back() {
        if (S.size() < 1) return;
        S.pop_back();
    }

    void front() {
        if (S.size() == 0) return print_empty();
        print(0);
    }

    void back() {
        if (S.size() == 0) return print_empty();
        print(S.size() - 1);
    }

    void srt(int l, int r) {
        int len = get_len(l, r);
        if (len) sort(S.begin() + l, S.begin() + l + len);
    }

    void rev(int l, int r) {
        int len = get_len(l, r);
        if (len) reverse(S.begin() + l, S.begin() + l + len);
    }

    void print(int pos) {
        if (pos >= S.size()) return print_empty();
        pnt(S[pos]);
    }

    void print(int l, int r) {
        int len = get_len(l, r);
        if (!len) return print_empty();

        pnt(S.substr(l, len));
    }

    void push_back(char ch) {
        S.push_back(ch);
    }
};

pair<int, int> get_range() {
    int l, r;
    cin >> l >> r;

    if (l > r) swap(l, r);

    return {l - 1, r - 1};
}

void solve() {
    int N, Q;
    string S;

    cin >> N >> Q >> S;
    Solver solver(S);

    while (Q--) {
        string op;
        cin >> op;

        if (op == "pop_back") solver.pop_back();
        if (op == "front") solver.front();
        if (op == "back") solver.back(); 
        if (op == "sort") {
            auto [l, r] = get_range();
            solver.srt(l, r);
        }
        if (op == "reverse") {
            auto [l, r] = get_range();
            solver.rev(l, r);
        }
        if (op == "print") {
            int pos;
            cin >> pos;
            solver.print(pos - 1);
        }
        if (op == "substr") {
            auto [l, r] = get_range();
            solver.print(l, r);
        }
        if (op == "push_back") {
            char ch;
            cin >> ch;
            solver.push_back(ch);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}