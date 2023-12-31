#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> pref_func(const string &s) {
    vector<int> pref(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        int c = pref[i - 1];
        while (c > 0 and s[i] != s[c]) c = pref[c - 1];
        if (s[i] == s[c]) pref[i] = c + 1;
    }
    return pref;
}

vector<int> pref_func(const string &s, const string &t) {
    vector<int> t_pref(t.size(), 0), pref(s.size(), 0);
    for (int i = 1; i < t.size(); ++i) {
        int c = t_pref[i - 1];
        while (c > 0 and t[i] != t[c]) c = t_pref[c - 1];
        if (t[i] == t[c]) t_pref[i] = c + 1;
    }
    if (!s.empty() and !t.empty()) pref[0] = (s[0] == t[0]) ? 1 : 0;
    for (int i = 1; i < s.size(); ++i) {
        int c = pref[i - 1];
        while (c > 0 and s[i] != t[c] or c == t.size()) c = t_pref[c - 1];
        if (s[i] == t[c]) pref[i] = c + 1;
    }
    return pref;
}

vector<int> z_func(const string &s) {
    int lb = 0, rb = 0;
    vector<int> z(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        if (i <= rb)
            z[i] = min(z[i - lb], rb - i + 1);
        while (i + z[i] < s.size() and s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > rb)
            lb = i, rb = i + z[i] - 1;
    }
    return z;
}

vector<int> z_func(const string &s, const string &t) {
    int lb = 0, rb = 0;
    vector<int> tz(t.size(), 0), z(s.size(), 0);
    for (int i = 1; i < t.size(); ++i) {
        if (i <= rb)
            tz[i] = min(tz[i - lb], rb - i + 1);
        while (i + tz[i] < t.size() and t[i + tz[i]] == t[tz[i]])
            tz[i]++;
        if (i + tz[i] - 1 > rb)
            lb = i, rb = i + tz[i] - 1;
    }
    while (z[0] < s.size() and z[0] < t.size() and t[z[0]] == s[z[0]]) z[0]++;
    lb = 0, rb = z[0] - 1;
    for (int i = 1; i < s.size(); ++i) {
        if (i <= rb)
            z[i] = min(tz[i - lb], rb - i + 1);
        while (i + z[i] < s.size() and z[i] < t.size() and s[i + z[i]] == t[z[i]])
            z[i]++;
        if (i + z[i] - 1 > rb)
            lb = i, rb = i + z[i] - 1;
    }
    return z;
}

vector<int> manacker_odd(const string &s) {
    vector<int> rad(s.size(), 1);
    int lb = 0, rb = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i <= rb)
            rad[i] = min(rad[lb + rb - i], rb - i + 1);
        while (0 <= i - rad[i] and i + rad[i] < s.size() and s[i - rad[i]] == s[i + rad[i]])
            rad[i]++;
        if (rb < i + rad[i] - 1)
            lb = i - rad[i] + 1, rb = i + rad[i] - 1;
    }
    return rad;
}

vector<int> manacker_even(const string &s) {
    vector<int> rad(s.size() - 1, 0);
    int lb = -1, rb = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (i <= rb)
            rad[i] = min(rad[lb + rb - i - 1], rb - i);
        while (0 <= i - rad[i] and i + rad[i] - 1 < s.size() and s[i - rad[i]] == s[i + rad[i] - 1])
            rad[i]++;
        if (rb < i + rad[i])
            lb = i - rad[i] + 1, rb = i + rad[i];
    }
    return rad;
}
