/*
Lesson: Don't insert or erase stuff while recursion as it can cause problems
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;
map<int, int> mp;
vector<int> arr;

void rec(int level) {
    if (level == n) {
        for (int num: arr) cout << num << " ";
        cout << endl;
        return;
    }

    for (auto &it: mp) {
        int num = it.first;
        
        if (it.second > 0) {
            it.second--;
            arr.push_back(num);

            rec(level + 1);

            arr.pop_back();
            it.second++;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        mp[num]++;
    }

    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}