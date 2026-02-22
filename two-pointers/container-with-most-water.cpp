#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        
        int ans = 0;
        int l = 0, r = N - 1;
        while (l < r) {
            int sw = min(height[l], height[r]) * (r - l);
            ans = max(ans, sw);

            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};