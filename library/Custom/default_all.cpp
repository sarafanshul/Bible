#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#include <random>
#include <cassert>
#include <chrono>
#define ALL(x) x.begin(),x.end() // custom alias
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
using namespace __gnu_pbds;
using namespace std;
#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef tree<
	long long, // Key type
	null_type, // Mapped-policy
	less<long long>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> // A policy for updating node invariants
ordered_set;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const long long MAXN = 1e6+7;

void check(){
	
}

signed main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#else
	cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif
	uint64_t t = 1;	
	// cin >> t;
	for(uint64_t i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
