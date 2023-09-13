#include <vector>

using namespace std;

int binary_search(const vector<int> &nums, int target) {
    int li = 0, ri = nums.size() - 1;
    while (li < ri) {
        int mi = li + (ri - li) / 2;
        if (nums[mi] == target) return mi;
        if (nums[mi] < target) li = mi + 1;
        else ri = mi - 1;
    }
    return (nums[li] == target) ? li : -1;
}

int lower_bound(const vector<int> &nums, int target) {
    int li = 0, ri = nums.size();
    while (li < ri) {
        int mi = li + (ri - li) / 2;
        if (nums[mi] < target) li = mi + 1;
        else ri = mi;
    }
    return li;
}

int upper_bound(const vector<int> &nums, int target) {
    int li = 0, ri = nums.size();
    while (li < ri) {
        int mi = li + (ri - li) / 2;
        if (nums[mi] <= target) li = mi + 1;
        else ri = mi;
    }
    return li;
}