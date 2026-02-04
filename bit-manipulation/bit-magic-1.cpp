#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

class Solver {
    int num = 0;

public:    
    int test(int pos) {
        return (num >> pos) & 1LL;
    }

    void set(int pos) {
        num |= (1LL << pos);
    }

    void clear(int pos) {
        num &= ~(1LL << pos);
    }

    void flip(int pos) {
        num ^= (1LL << pos);
    }

    int all() {
        return num == ((1LL << 60) - 1);
    }

    int any() {
        return num > 0;
    }

    int none() {
        return num == 0;
    }

    int count() {
        int val = num;
        
        int ans = 0;
        while (val) {
            val &= (val - 1);
            ans++;
        }

        return ans;
    }

    int val() {
        return num;
    }
};

void print(int x) {
    cout << x << endl;
}

int get_curr_input() {
    int x;
    cin >> x;

    return x;
}

void solve() {
    int q;
    cin >> q;

    Solver solver; 
    while (q--) {
        int op;
        cin >> op;

        switch (op) {
            case 1: print(solver.test(get_curr_input())); break;
            case 2: solver.set(get_curr_input()); break;
            case 3: solver.clear(get_curr_input()); break;
            case 4: solver.flip(get_curr_input()); break;
            case 5: print(solver.all()); break;
            case 6: print(solver.any()); break;
            case 7: print(solver.none()); break;
            case 8: print(solver.count()); break;
            case 9: print(solver.val()); break;
            default: break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}