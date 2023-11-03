#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> tree;

    static int back(int idx) { return idx & (idx + 1); }
    static int forw(int idx) { return idx | (idx + 1); }

    int pref(int rb) {
        int sum = 0;
        while (rb >= 0) {
            sum += tree[rb];
            rb = back(rb) - 1;
        }
        return sum;
    }

    Fenwick(const vector<int> &src) {
        if (src.empty()) return;
        vector<int> pref{src.front()};
        pref.reserve(src.size());
        tree.push_back(src.front());
        tree.reserve(src.size());

        for (int i = 1; i < src.size(); ++i) {
            pref.push_back(pref.back() + src[i]);
            tree.push_back(pref[i]);
            if (back(i) > 0) tree.back() -= pref[back(i) - 1];
        }
    }

    int get(int lb, int rb) { return pref(rb) - ((lb > 0) ? pref(lb - 1) : 0); }

    void mod(int idx, int diff) {
        while (idx < tree.size()) {
            tree[idx] += diff;
            idx = forw(idx);
        }
    }

    void set(int idx, int val) { mod(idx, val - get(idx, idx)); }
};
