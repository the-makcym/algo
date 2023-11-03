#include <bits/stdc++.h>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

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

namespace ArrayTrie {
struct TrieNode {
    TrieNode* suc[26] = {nullptr};
    size_t cnt = 0;
};

struct Trie {
    TrieNode root;
    FixedAlloca<TrieNode> alloca;

    Trie() = default;

    void insert(const string& s) {
        auto node = &root;
        for (char c : s) {
            if (node->suc[c - 'a'] == nullptr)
                node->suc[c - 'a'] = alloca.get();
            node = node->suc[c - 'a'];
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
            if (node->suc[c - 'a'] == nullptr) return nullptr;
            node = node->suc[c - 'a'];
        }
        return node;
    }
};
}  // namespace ArrayTrie

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
