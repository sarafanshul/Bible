//  -== BIT ==
//
// ===== 0 BASED - INDEXING ====
//
//
//  === resources ===
// https://www.youtube.com/watch?v=kPaJfAUwViY
// https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
// https://cp-algorithms.com/data_structures/fenwick.html
//


// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
//      // for overflow
#define int long long
// #define INT_MAX LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;

// i += i & -i sum
// i -= i & -i add
struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	int n ,q ,x ,y ,z;
	cin >> n >> q;
	vector<int> a(n);
	for(size_t i = 0 ;i < n ;i++) cin >> a[i];
	
	FenwickTreeOneBasedIndexing ft(a);
	// code here
	
	return 0;
}
