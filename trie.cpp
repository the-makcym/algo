#include <bits/stdc++.h>
using namespace std;

// фиксированный аллокатор сильно ускоряет создание новых узлов дерева
template <class T>
struct FixedAlloca {
    const size_t size = sizeof(T) * 1000;
    char* beg = nullptr;
    char* end = nullptr;
    char* nxt = nullptr;

    T* get() {
        if (nxt == end) {
            beg = (char*)malloc(size);
            end = beg + size;
            nxt = beg;
        }
        auto ptr = new (nxt) T;
        nxt += sizeof(T);
        return ptr;
    }
};

// префиксное дерево, англяз. название - trie (от retrieve, читается как трай)
// представляет множество слов в виде дерева
// можно отвечать на вопросы типа а есть ли слово в нашем множестве?
// https://ru.algorithmica.org/cs/string-structures/trie/

// кстати, трай можно использовать для хеширования большого количества слов:
// (дело в том, что плюсы из коробки не умеют в хеширование строк, что может
// быть полезно для unordered_map)
// 1. строим трай для слов
// 2. хеш слова = хеш указателя, возвращаемого search

// suc = successor
// cnt = count

// хранит последующие узлы в виде массива полагая размер алфавита фиксированным
// и небольшим
namespace ArrayTrie {
// узел дерева
// при этом буквы обозначаются не столько самими узлами, сколько переходами
// между ними
struct TrieNode {
    // массив указателей на нижеследующие узлы (последующие буквы слова)
    // индекс буквы char letter считается как letter - 'a'
    TrieNode* suc[26] = {nullptr};
    // сколько слов заканчиваются в этой вершине
    // даже если каждое слово уникально и встретиться может только однажды,
    // стоит отсечь мысль использовать булевый флаг окончания слова для экономии
    // места - выравнивание структур все равно будет использовать для этого поля
    // 8 байт
    size_t cnt = 0;
};

struct Trie {
    // корень дерева, никакую букву не обозначает, это скорее невидимая буква
    // перед первой буквой слова
    TrieNode root;
    FixedAlloca<TrieNode> alloca;

    Trie() = default;

    // вставить новое слово s
    void insert(const string& s) {
        auto node = &root;
        for (char c : s) {
            if (node->suc[c - 'a'] == nullptr)
                node->suc[c - 'a'] = alloca.get();
            node = node->suc[c - 'a'];
        }
        node->cnt++;
    }

    // сколько таких слов у нас есть
    size_t count(const string& s) {
        auto node = search(s);
        return node == nullptr ? 0 : node->cnt;
    }

    // есть ли такое слово у нас, если есть - получай узел с последней буквой
    TrieNode* search(const string& s) {
        auto node = &root;
        for (char c : s) {
            if (node->suc[c - 'a'] == nullptr) return nullptr;
            node = node->suc[c - 'a'];
        }
        return node;
    }
};
}  // namespace ArrayTrie

// все аналогично, только нижележащие узлы храним теперь не в массиве, а в
// словаре
namespace MapTrie {
struct TrieNode {
    map<char, TrieNode*> suc;
    size_t cnt = 0;
};

struct Trie {
    TrieNode root;
    FixedAlloca<TrieNode> alloca;

    Trie() = default;

    void insert(const string& s) {
        auto node = &root;
        for (char c : s) {
            if (node->suc.count(c) == 0) node->suc.emplace(c, alloca.get());
            node = node->suc[c];
        }
        node->cnt++;
    }

    size_t count(const string& s) {
        auto node = search(s);
        return node == nullptr ? 0 : node->cnt;
    }

    TrieNode* search(const string& s) {
        auto node = &root;
        for (char c : s) {
            if (node->suc.count(c) == 0) return nullptr;
            node = node->suc[c];
        }
        return node;
    }
};
}  // namespace MapTrie
