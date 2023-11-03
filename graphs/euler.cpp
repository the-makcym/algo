#include <bits/stdc++.h>

using namespace std;

// don't forget to reverse resulting vector
void euler(vector<unordered_set<int>> &graph, vector<int> &path, int src = 0) {
    while (!graph[src].empty()) {
        int dst = *graph[src].begin();
        graph[src].erase(dst);
        // only for directed graph
        graph[dst].erase(src);
        euler(graph, path, dst);
    }
    path.push_back(src);
}
