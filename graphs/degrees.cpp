#include <bits/stdc++.h>

using namespace std;

vector<int> undir_degrees(const vector<vector<int>> &graph) {
    vector<int> deg(graph.size(), 0);
    for (const auto &src : graph) {
        for (int dst : src) {
            deg[dst]++;
        }
    }
    return deg;
}

pair<vector<int>, vector<int>> dir_degrees(const vector<vector<int>> &graph) {
    vector<int> in(graph.size(), 0), out(graph.size(), 0);
    for (int src = 0; src < graph.size(); ++src) {
        for (int dst : graph[src]) {
            in[dst]++;
            out[src]++;
        }
    }
    return {in, out};
}