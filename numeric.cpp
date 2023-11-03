#include <bits/stdc++.h>

using namespace std;

int two_power(int num) {
    if (num == 0 or num == (1 << (__lg(num))))
        return num;
    return 1 << (__lg(num) + 1);
}
