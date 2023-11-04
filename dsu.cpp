#include <bits/stdc++.h>

using namespace std;

// DSU = disjoint sets union = система непересекющихся множеств
// https://habr.com/ru/articles/104772/
// если есть некоторые элементы, то с этой штукой их можно объединять в множества
// а точнее, получится делать только две вещи:
// 1. понимать, лежат ли два элемента в одном множестве или в разных
// 2. сливать два множества в одно
// больше ничего не получится, но зато эта штука работает в среднем за константу
// изначально каждый элемент лежит в множестве, состоящей из одного себя

// rng = Random Number Generator
// idx = index
// lhs = Left Hand Side operand
// rhs = Right Hand Side operand

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
