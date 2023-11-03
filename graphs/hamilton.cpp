#include <bits/stdc++.h>

using namespace std;

int shortest_hamilton_path(int mask, int end, vector<vector<int>> &dp,
                           const vector<unordered_map<int, int>> &graph) {
    if ((mask & (mask - 1)) == 0) return 0;
    if (dp[mask][end] != -1) return dp[mask][end];

    int len = INT32_MAX;
    for (int bit = 0; bit < 32; ++bit) {
        if ((mask & (1 << bit)) == 0) continue;
        if (graph[bit].count(end) == 0) continue;
        len = min(len,
                  shortest_hamilton_path(mask & ~(1 << end), bit, dp, graph) +
                      graph[bit].find(end)->second);
    }

    return dp[mask][end] = len;
}

int count_hamilton_paths(int mask, int end, vector<vector<int>> &dp,
                         const vector<unordered_set<int>> &graph) {
    if ((mask & (mask - 1)) == 0) return 1;
    if (dp[mask][end] != -1) return dp[mask][end];

    int cnt = 0;
    for (int bit = 0; bit < 32; ++bit) {
        if ((mask & (1 << bit)) == 0) continue;
        if (graph[bit].count(end) == 0) continue;
        cnt += count_hamilton_paths(mask & ~(1 << end), bit, dp, graph);
    }

    return dp[mask][end] = cnt;
}

int check_hamilton_path(int mask, vector<int> &dp, const vector<int> &graph) {
    if ((mask & (mask - 1)) == 0) return mask;
    if (dp[mask] != -1) return dp[mask];

    int ans = 0;
    for (int bit = 0; bit < 32; ++bit) {
        if ((mask & (1 << bit)) == 0) continue;
        if ((check_hamilton_path(mask & ~(1 << bit), dp, graph) & graph[bit]) !=
            0)
            ans += 1 << bit;
    }

    return dp[mask] = ans;
}
