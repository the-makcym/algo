#include <vector>
#include <random>
#include <chrono>

using namespace std;

struct DSU {
    vector<int> parents;
    mt19937 rng;

    explicit DSU(int capacity) {
        parents.reserve(capacity);
        rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    }

    DSU(int capacity, int n) {
        parents.reserve(capacity);
        insert(n);
        rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    }

    void insert() {
        parents.push_back(parents.size());
    }

    void insert(int n) {
        for (int i = 0; i < n; ++i)
            parents.push_back(parents.size());
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