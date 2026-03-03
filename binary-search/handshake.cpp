/*
https://atcoder.jp/contests/abc149/tasks/abc149_e
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int N, M;
int arr[100001];

int cnt_guest;

bool check(int H) {
    int cnt_residue = M - cnt_guest * cnt_guest;

    int power_part1 = 0;
    int power_part2 = 0;

    int copy_cnt_guest = cnt_guest;
    int copy_cnt_residue = cnt_residue;
    for (int i = N - 1; i >= 0; i--) {
        if (copy_cnt_guest > 0) {
            power_part1 += 2 * cnt_guest * arr[i];
            copy_cnt_guest--;
        } else {
            power_part2 += cnt_residue * arr[i];
            break;
        }

        if (copy_cnt_residue > 0) {
            power_part2 += arr[i];
            copy_cnt_residue--;
        }
    }

    return (power_part1 + power_part2) >= H;
}

void solve() {
    cin >> N >> M;
    cnt_guest = sqrt(M);

    int mx = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        arr[i] = num;
        mx = max(mx, num);
        sum += num;
    };

    sort(arr, arr + N);

    int ans = -1;

    int l = 2 * mx, r = 2 * N * sum;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}