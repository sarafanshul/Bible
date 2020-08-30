//  -== BIT ==
//
// ===== 0 BASED - INDEXING ====
//
// IMPORTANT
//It is obvious that there is no easy way of finding minimum of range 
// [l,r] using Fenwick tree, as Fenwick tree can only answer queries of type 
// 	[0,r]. 
//Additionally, each time a value is update'd, the new value has to be smaller than the current value (because the min function is not reversible). These, of course, are significant limitations.
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
#define INF LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;

struct FenwickTreeMin {
    vector<int> bit;
    int n;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> &a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	int n ,q ,x ,y ,z;
	cin >> n >> q;
	vector<int> a(n);
	for(size_t i = 0 ;i < n ;i++) cin >> a[i];
	
	FenwickTreeMin ft(a);

	while(q--){
		cin >> x >> y >> z;
		if(x == 1){ft.update(y ,z);}
		else cout << ft.getmin(y);
	}

	return 0;
}
