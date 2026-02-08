#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;
using ull = unsigned long long;

class Solver {
    ll num;
    ull unum; 

public:
    Solver(ll num) {
        this->num = num;
        this->unum = (ull)num;
    }
    
    void print_binary_form() {
        for (int pos = 63; pos >= 0; pos--) {
            cout << ((unum >> pos) & 1);
        }

        cout << endl;
    }

    ll find_msb() {
        if (unum == 0) return -1;
        return 63 - __builtin_clzll(unum);
    }

    ll find_lsb() {
        if (unum == 0) return -1;
        return __builtin_ctzll(unum);
    }

    ll is_power_two() {
        if (num <= 1) return 0;
        return ((unum & (unum - 1)) == 0 ? 1 : 0);
    }

    ll biggest_divisor_power() {
        if (num == 0) return -1;

        return (1LL << find_lsb());
    }

    ll smallest_power_gte_num() {
        if (num <= 1) return 2;  

        if (is_power_two()) return num;
        return 1LL << (find_msb() + 1); 
    }
};

void print(ll num) {
    cout << num << endl;
};

void solve() {
    ll n;
    cin >> n;

    Solver solver(n);
    solver.print_binary_form();
    print(solver.find_msb());
    print(solver.find_lsb());
    print(solver.is_power_two());
    print(solver.biggest_divisor_power());
    print(solver.smallest_power_gte_num());
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}