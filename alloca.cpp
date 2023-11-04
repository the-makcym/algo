#include <bits/stdc++.h>

// Аллокатор
// Можно использовать, когда надо создавать заведомо много объектов на куче
// По сути используется, чтобы застолбить кусок памяти, чтоб стандартный аллокатор его не схавал, так быстрее
// Можно использовать, например, в префиксном дереве

template <class T>
class FixedAlloca {
    const size_t size = sizeof(T) * 1000;
    char *beg = nullptr;
    char *end = nullptr;
    char *nxt = nullptr;

   public:
    T *get() {
        if (nxt == end) {
            beg = (char *)malloc(size);
            end = beg + size;
            nxt = beg;
        }
        auto ptr = new (nxt) T;
        nxt += sizeof(T);
        return ptr;
    }
};
