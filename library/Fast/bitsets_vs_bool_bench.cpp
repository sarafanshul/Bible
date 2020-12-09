https://codeforces.com/blog/entry/77480?#comment-623333

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include <bits/stdc++.h>

using namespace std;
struct timeit {
    decltype(chrono::high_resolution_clock::now()) begin;
    const string label;
    timeit(string label = "???") : label(label) { begin = chrono::high_resolution_clock::now(); }
    ~timeit() {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
        cout << duration << "ms elapsed [" << label << "]" << endl;
    }
};

const int MAXN = 1e4;
const int iters = 1e5;

bool a[MAXN], b[MAXN];
signed main() {
    {
        srand(0);
        bitset<MAXN> a, b;
        for (int i = 0; i < MAXN; i++) {
            a[i] = rand() % 2, b[i] = rand() % 2;
        }
        timeit x("bitset");
        int cnt = 0;
        for (int it = 0; it < iters; it++) {
            cnt += (a & b).count();
        }
        cout << cnt<< endl;
    }
        {
        srand(0);
        bool a[MAXN], b[MAXN];
        for (int i = 0; i < MAXN; i++) {
            a[i] = rand() % 2, b[i] = rand() % 2;
        }
        timeit x("bool");
        int cnt = 0;
        for (int it = 0; it < iters; it++) {
            for (int i = 0; i < MAXN; i++) {
                if (a[i] & b[i])
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
}
