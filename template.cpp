#include <bits/stdc++.h>

#include <strstream>

using namespace std;

// шаблон, чтоб переключаться между тестированием и сдачей решения

using uns = unsigned int;
using ill = long long int;
using ull = unsigned long long;

#define prique priority_queue
#define set_m multiset
#define map_m multimap
#define hashset unordered_set
#define hashmap unordered_map
#define hashset_m unordered_multiset
#define hashmap_m unordered_multimap

// само решение, принимает на вход cin, возвращает ответ в поток типа ostrstream
class Solution {
   public:
    ostrstream solution(istream &input) {}
};

// тесты
void test() {
    Solution sol;
    {
        istrstream input("");
        auto output = sol.solution(input).str();
        auto answer = "";
        assert(output == answer);
    }
}

// решение
void solve() {
    Solution sol;
    cout << sol.solution(cin).str();
}

int main() {
    test();
    // solve();
}