const char sp = ' ';
const char nl = '\n';
#define print(x) cout << x << nl

class Solution {
    using ll = long long;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll lcm_ab = lcm(a, b);
        ll lcm_bc = lcm(b, c);
        ll lcm_ac = lcm(a, c);
        ll lcm_abc = lcm(lcm_ab, c);

        auto count = [&](ll x) {
            return (
                (x / a) + (x / b) + (x / c)
                - (x / lcm_ab) - (x / lcm_bc) - (x / lcm_ac)
                + (x / lcm_abc)
            );
        };

        ll s = 1, e = 2e9;
        ll ans = -1;

        while (s <= e) {
            ll mid = s + (e - s) / 2;

            if (count(mid) >= n) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};