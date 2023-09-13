#include <vector>

using namespace std;

class Fenwick {
    vector<int> data;

    static int pred(int idx) {
        return idx & (idx + 1);
    }

    static int succ(int idx) {
        return idx | (idx + 1);
    }

    int pref(int rb) {
        int sum = 0;
        while (rb >= 0) {
            sum += data[rb];
            rb = pred(rb) - 1;
        }
        return sum;
    }

public:
    explicit Fenwick(size_t size, int val = 0) {
        if (!size) return;
        data.push_back(val);
        data.reserve(size);
        for (int i = 1; i < size; ++i)
            data.push_back(val * (i + 1 - pred(i)));
    }

    explicit Fenwick(const vector<int> &arr) {
        if (arr.empty()) return;
        vector<int> pref{arr.front()};
        pref.reserve(arr.size());
        data.push_back(arr.front());
        data.reserve(arr.size());

        for (int i = 1; i < arr.size(); ++i) {
            pref.push_back(pref.back() + arr[i]);
            data.push_back(pref[i]);
            if (pred(i) > 0) data.back() -= pref[pred(i) - 1];
        }
    }

    int get(int lb, int rb) {
        return pref(rb) - ((lb > 0) ? pref(lb - 1) : 0);
    }

    void mod(int idx, int diff) {
        while (idx < data.size()) {
            data[idx] += diff;
            idx = succ(idx);
        }
    }

    void set(int idx, int val) {
        mod(idx, val - get(idx, idx));
    }
};