#include <bits/stdc++.h>
using namespace std;

class DSU {
    int n, components;
    vector<int> rep, rank;

public:
    DSU(int n): n(n), components(n), rep(n + 2), rank(n + 1, 1) {
        for (int i = 1; i <= n; i++) rep[i] = i;
    }

    int find(int node) {
        if (rep[node] == node) return node;

        return rep[node] = find(rep[node]);
    }

    void merge(int node1, int node2) {
        int rep1 = find(node1), rep2 = find(node2);

        if (rep1 == rep2) return;

        if (rank[rep1] < rank[rep2]) swap(rep1, rep2);

        rep[rep2] = rep1;
        rank[rep1] += rank[rep2];

        this->components--;
    }

    int get_components() {
        return this->components;
    }

    int get_size(int node) {
        if (node < 1 || node > n) return 0;

        return this->rank[node];
    }
};

class Solution {
public:
    vector<int> get_pfactors(int num) {
        vector<int> ans;

        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                ans.push_back(d);

                while (num % d == 0) {
                    num /= d;
                }
            }
        }

        if (num > 1) ans.push_back(num);

        return ans; 
    }

    int largestComponentSize(vector<int>& nums) {
        DSU dsu(100000);

        for (int num: nums) {
            vector<int> factors = get_pfactors(num);

            for (int factor: factors) {
                dsu.merge(factor, num);
            }
        }

        map<int, int> cnt;
        int ans = 0;

        for (int num: nums) {
            int rep = dsu.find(num);
            
            cnt[rep]++;
            ans = max(ans, cnt[rep]); 
        }

        return ans;
    }
};