#include <bits/stdc++.h>
using namespace std;

// стандартные обходы
// граф представляется в виде связного списка

// q = queue
// vis = visited
// cur = current
// dst = destination
// idx = index

// breadth-first search, обход в ширину
// главное применение - поиск кратчайшего пути
// (для поиска кратчайших путей от одного до всех или от всех до всех есть другие алгосы)
void bfs(const vector<vector<int>> &graph) {
    // очередь вершин на посещение
    queue<int> q;
    // 0 for example
    q.push(0);
    // пометка посещенных вершин
    vector<bool> vis(graph.size(), false);
    // важно помечать вершину посещенной до того, как вошли туда
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

// depth-first search, рекурсивный обход в глубину
// считает заодно и tin, tout (time in/out) - время входа и выхода из вершины
// можно циклы искать, можно компоненты связности, в кратчайшие маршруты не умеет
// https://ru.algorithmica.org/cs/graph-traversals/dfs/
void dfs(int idx, int time, const vector<vector<int>> &graph, vector<bool> &vis,
         vector<int> &tin, vector<int> &tout) {
    vis[idx] = true;
    tin[idx] = time++;

    for (int dst : graph[idx])
        if (!vis[dst]) dfs(dst, time, graph, vis, tin, tout);

    tout[idx] = time;
}

// one more depth-first search, итеративный обход в глубину
// почти всегда медленней рекурсивного, менее гибок, не может в backtracking, писать неудобно
// 1/10, но сама идея интересная
// https://www.geeksforgeeks.org/iterative-depth-first-traversal/
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
