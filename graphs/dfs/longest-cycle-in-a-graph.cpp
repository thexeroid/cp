/*
Link: https://leetcode.com/problems/longest-cycle-in-a-graph/
*/

#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
#define F first
#define S second

class Solution {
    int n;
    vector<int>* adj;
    vector<P> mp;

    void init(vector<int> &edges) {
        n = edges.size();
        
        mp.assign(n, {0, INT_MAX});
        adj = &edges;
    }

    int dfs(int node) {
        auto &g = *adj;

        mp[node].F = 1;

        int ans = -1;
        int neigh = g[node];
        if (neigh != -1) {
            if (mp[neigh].F == 0) {
                mp[neigh].S = mp[node].S + 1;
                ans = max(ans, dfs(neigh));
            }

            if (mp[neigh].F == 1) {
                ans = max(ans, mp[node].S - mp[neigh].S + 1);
            }
        }

        mp[node].F = 2;

        return ans;
    }

public:
    int longestCycle(vector<int>& edges) {
        init(edges);

        int ans = -1;
        for (int node = 0; node < n; node++) {
            if (!mp[node].F) {
                mp[node].S = 0;
                ans = max(ans, dfs(node));
            }
        }

        return ans;
    }
};