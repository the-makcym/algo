#include <bits/stdc++.h>

using namespace std;

// находит эйлеров цикл - цикл по всем ребрам
// критерий существования эйлерова цикла - степени всех вершин четны
// чтоб пользоваться этим алгосом, надо проверить четность всех вершин
// подробнее: https://ru.algorithmica.org/cs/graph-traversals/euler-cycle/

// можно найти так же эйлеров путь
// критерий его существования - степени всех вершин, кроме двух, четны
// запускаться (src) тогда надо из любой из двух нечетных вершин

// предполагается, что граф неориентированный
// представлен в виде массива множеств смежных вершин

// src = source
// dst = destination

// don't forget to reverse resulting vector
void euler(vector<unordered_set<int>> &graph, vector<int> &path, int src = 0) {
    while (!graph[src].empty()) {
        int dst = *graph[src].begin();
        graph[src].erase(dst);
        // only for undirected graph
        graph[dst].erase(src);
        euler(graph, path, dst);
    }
    path.push_back(src);
}
