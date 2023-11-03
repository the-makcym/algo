#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parents;
    mt19937 rng;

    DSU(int n) {
        parents.resize(n);
        for (int i = 0; i < n; ++i) parents[i] = i;
        rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    }

    int find(int idx) {
        if (parents[idx] == idx) return idx;
        int root = find(parents[idx]);
        parents[idx] = root;
        return root;
    }

    void unite(int lhs, int rhs) {
        if (rng() % 2) parents[find(lhs)] = find(rhs);
        else parents[find(rhs)] = find(lhs);
    }
};
