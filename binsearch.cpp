#include <bits/stdc++.h>

using namespace std;

// бинарный поиск, ни добавить, ни убавить
// предполагается, что массивы отсортированы по возрастанию

// lb = left bound
// rb = right bound
// md = middle

// индекс элемента, если его нет - то -1
int binary_search(const vector<int> &nums, int target) {
    int lb = 0, rb = nums.size() - 1;
    while (lb < rb) {
        int md = lb + (rb - lb) / 2;
        if (nums[md] == target) return md;
        if (nums[md] < target)
            lb = md + 1;
        else
            rb = md - 1;
    }
    return (nums[lb] == target) ? lb : -1;
}

// первый индекс, который может занять данный элемент, не нарушив порядка
// возрастания
int lower_bound(const vector<int> &nums, int target) {
    int lb = 0, rb = nums.size();
    while (lb < rb) {
        int md = lb + (rb - lb) / 2;
        if (nums[md] < target)
            lb = md + 1;
        else
            rb = md;
    }
    return lb;
}

// последний индекс, который может занять данный элемент, не нарушив порядка
// возрастания
int upper_bound(const vector<int> &nums, int target) {
    int lb = 0, rb = nums.size();
    while (lb < rb) {
        int md = lb + (rb - lb) / 2;
        if (nums[md] <= target)
            lb = md + 1;
        else
            rb = md;
    }
    return lb;
}
