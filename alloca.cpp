#include <string>

template<class T>
class FixedAlloca {
    const size_t size = sizeof(T) * 1000;
    char *beg = nullptr;
    char *end = nullptr;
    char *nxt = nullptr;

public:
    T *get() {
        if (nxt == end) {
            beg = (char *) malloc(size);
            end = beg + size;
            nxt = beg;
        }
        auto ptr = new(nxt) T;
        nxt += sizeof(T);
        return ptr;
    }
};