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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            _add(i, a[i]);
    }

    int _sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int _sum(int l, int r) {
        return _sum(r) - _sum(l - 1);
    }

    void _add(int idx, int delta) {
        // cout <<"idx->"<<idx<<  " d->"<<delta<<" -- ";
        for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
		
// 		for(size_t i = 0; i < bit.size(); i++ ) cout<<  bit[i] << " ";
//         cout << "\n";
    }   
    
};


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	int n ,q ,x ,y ,z;
	cin >> n >> q;
	vector<int> a(n);
	for(size_t i = 0 ;i < n ;i++) cin >> a[i];
	
	FenwickTree ft(a);

	while(q--){
	   // cout << "--\n";
		cin >> x >> y >> z;
		if(x == 1) {
		    ft._add(y ,z - a[y]);
		    a[y] = z; // forgot to update a LOL
		}
		else cout << ft._sum(y ,z-1) << "\n";
	}

	return 0;
}
