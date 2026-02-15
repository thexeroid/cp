using ll = long long;

class Solution {
public:
    ll count_set_till_num(ll num, ll pos_const) {
        ll ans = 0;
        for (int i = pos_const - 1; i < 62; i+=pos_const) {
            ll part1 = ((num + 1) >> (i + 1)) << i;
            ll part2 = ((num + 1) & ((1LL << (i + 1)) - 1)) - (1LL << i);
            ans += (part1 + (part2 > 0 ? part2 : 0));
        }

        return ans;
    }

    bool check(ll num, ll pos_const, ll upper_cap) {
        return count_set_till_num(num, pos_const) <= upper_cap;
    }

    ll findMaximumNumber(ll k, int x) {
        ll low = 1, high = 1e15;
        ll ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(mid, x, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};