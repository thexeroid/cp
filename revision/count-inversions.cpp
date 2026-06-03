/*

Master's theorem:

T(n) = a * T(n / b) + f(n)

We compare f(n) with O(n^k * log(n)^p)

To find:
1. a
2. b
3. k
4. p
5. log_b(a)

if log_b(a) > k: O(n^log_b(a))
if log_b(a) == k:
    if p > -1: O(n^k * log(n)^(p + 1))
    if p == -1: O(n^k * loglogn)
    if p < -1: O(n^k)
if log_b(a) < k:
    if p >= 0: O(n^k * log(n)^p)
    if p < 0: O(n^k)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

int n;
int A[100001];

int buffer[100001];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

ll merge(int start, int end) {
    int bf_idx = start;

    int mid = (start + end) / 2;
    int s1 = start, s2 = mid + 1;

    ll ans = 0;
    while (s1 <= mid && s2 <= end) {
        if (A[s1] > A[s2]) {
            ans += (mid - s1 + 1);
            buffer[bf_idx] = A[s2];
            s2++;
        } else {
            buffer[bf_idx] = A[s1];
            s1++;
        }

        bf_idx++;
    }

    while (s1 <= mid) {
        buffer[bf_idx] = A[s1];
        s1++;
        bf_idx++;
    }

    while (s2 <= mid) {
        buffer[bf_idx] = A[s2];
        s2++;
        bf_idx++;
    }

    for (int i = start; i <= end; i++) {
        A[i] = buffer[i]; 
    }

    return ans;
}

ll sort(int start, int end) {
    if (start >= end) return 0;

    int mid = (start + end) / 2;

    ll ans = 0;
    ans += sort(start, mid);
    ans += sort(mid + 1, end);
    ans += merge(start, end);

    return ans;
}

void solve() {
    init();
    
    print(sort(0, n - 1));
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