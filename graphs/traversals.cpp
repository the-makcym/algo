#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>> &graph) {
    queue<int> q;
    q.push(0);
    vector<bool> vis(graph.size(), false);
    vis[0] = true;

    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; ++i) {
            int cur = q.front();
            for (int dst : graph[cur]) {
                if (!vis[dst]) {
                    q.push(dst);
                    vis[dst] = true;
                }
            }
            q.pop();
        }
    }
}

void dfs(int idx, int time, const vector<vector<int>> &graph, vector<bool> &vis,
         vector<int> &tin, vector<int> &tout) {
    vis[idx] = true;
    tin[idx] = time++;

    for (int dst : graph[idx])
        if (!vis[dst]) dfs(dst, time, graph, vis, tin, tout);

    tout[idx] = time;
}

void dfs(const vector<vector<int>> &graph) {
    vector<int> stack;
    vector<bool> vis(graph.size(), false);

    for (int src = 0; src < graph.size(); ++src) {
        if (vis[src]) continue;
        stack.push_back(src);
        vis[src] = true;
        while (!stack.empty()) {
            int cur = stack.back();
            stack.pop_back();
            for (int dst : graph[cur]) {
                if (!vis[dst]) {
                    stack.push_back(dst);
                    vis[dst] = true;
                }
            }
        }
    }
}
