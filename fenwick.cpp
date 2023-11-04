#include <bits/stdc++.h>
using namespace std;

// дерево Фенвика, аналог дерева отрезков (ДО) с некоторыми ограничениями
// англояз. название - Binary Indexed Tree
// https://www.youtube.com/watch?v=muW1tOyqUZ4
// https://ru.algorithmica.org/cs/range-queries/fenwick/
// предназначено только для обратимых операций
// напр.: сложение, умножение на не ноль, xor
// (обратные: вычитание, деление, xor соответственно)
// взятие остатков, побитовые &, | не подходят
// хотя для максимума его можно приспособить, но только если изменения элементов
// будут только увеличивать их

// как и ДО:
// 1. изменить одного элемента в массиве
// 2. получить результат операции над всеми элементами на нек. отрезке
// работает несколько быстрее ДО, памяти занимает в 4 раза меньше

// pred = predecessor
// succ = successor
// src = source
// prefix = prefix sums
// lb = left bound
// rb = right bound
// idx = index
// diff = difference
// val = value
// mod = modify

// полагаем, что дерево строится для сложения

struct Fenwick {
    vector<int> tree;

    // в tree[i] лежит сумма элементов на отрезке [pred(i) : i]
    static int pred(int idx) { return idx & (idx + 1); }
    // i-ое элемент входит как слагаемое в значение tree[succ(i)],
    // tree[succ(succ(i))] ...
    static int succ(int idx) { return idx | (idx + 1); }

    // строит дерево на данном массиве за линейное время
    Fenwick(const vector<int> &src) {
        if (src.empty()) return;
        vector<int> prefix{src.front()};
        prefix.reserve(src.size());
        tree.push_back(src.front());
        tree.reserve(src.size());

        for (int i = 1; i < src.size(); ++i) {
            prefix.push_back(prefix.back() + src[i]);
            tree.push_back(prefix[i]);
            if (pred(i) > 0) tree.back() -= prefix[pred(i) - 1];
        }
    }

    // сумма на префиксе [0, rb]
    int get(int rb) {
        int sum = 0;
        while (rb >= 0) {
            sum += tree[rb];
            rb = pred(rb) - 1;
        }
        return sum;
    }

    // сумма на отрезке [lb, rb]
    int get(int lb, int rb) { return get(rb) - ((lb > 0) ? get(lb - 1) : 0); }

    // увеличить элемент с данным индексом
    void mod(int idx, int diff) {
        while (idx < tree.size()) {
            tree[idx] += diff;
            idx = succ(idx);
        }
    }

    // изменить элемент с данным индексом
    void set(int idx, int val) { mod(idx, val - get(idx, idx)); }
};
