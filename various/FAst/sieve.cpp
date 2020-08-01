#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
const int MAXN = 200000;


template<int N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (int i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (int i = 2; i < N; i++) if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
};

template<Sieve<MAXN> s>
struct SieveWrapper {
    static bool get(int n) {
        return s.is_prime[n];
    }
};

bool is_prime(int n) {
    return SieveWrapper<Sieve<MAXN>{}>::get(n);
}

    
int main() {
    auto t1 = time(NULL);
    
    // compute answer for 1000 random integers
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans += is_prime(rand() % MAXN);
    }

    auto t = time(NULL) - t1;

    std::cout << "Answer: " << ans << ". Elapsed time: " << t << "s" << std::endl;
}