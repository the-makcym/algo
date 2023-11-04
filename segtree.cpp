#include <bits/stdc++.h>
using namespace std;

// дерево отрезков
// умеет в
// 1. изменять элемент по данному индексу
// 2. результат групповой операции над всеми элементами на нек. отрезке
// операции - любые: +, *, %, max, min, xor, &, |, gcd
// все делает за логарифм, построение за линейное время
// https://ru.algorithmica.org/cs/segment-tree/

// op = operation
// lhs = Left Hand Side operand
// rhs = Right Hand Side operand
// src = source
// lb = left bound
// rb = right bound
// lmc = LeftMost Child
// hf = half length
// mod = modify
// diff = difference

struct Segtree {
    vector<int> tree;

    inline int op(int lhs, int rhs) { return max(lhs, rhs); }

    // строит дерево на данном массиве
    Segtree(const vector<int> &src) {
        if (src.empty()) return;

        int size = src.size();
        if (size != (1 << __lg(size))) size = 1 << (__lg(size) + 1);
        tree.resize(size * 2);

        copy(src.begin(), src.end(), tree.begin() + size);
        for (int i = size - 1; i > 0; --i)
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
    }

    // результат операции на отрезке
    int get(int lb, int rb, int i = 1, int lmc = 0, int len = -1) {
        if (len < 0) len = tree.size() / 2;

        int hf = len / 2;
        if (lb <= lmc and lmc + len - 1 <= rb) return tree[i];
        if (rb < lmc + hf) return get(lb, rb, i * 2, lmc, hf);
        if (lmc + hf <= lb) return get(lb, rb, i * 2 + 1, lmc + hf, hf);

        return op(get(lb, lmc + hf - 1, i * 2, lmc, hf),
                  get(lmc + hf, rb, i * 2 + 1, lmc + hf, hf));
    }

    // изменить значение одного элемента
    void mod(int i, int diff) {
        i += tree.size() / 2;
        tree[i] += diff;
        i /= 2;
        while (i > 0) {
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
            i /= 2;
        }
    }
};
