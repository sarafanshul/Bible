// does not work NOW

#pragma GCC optimize("Ofast")  // Compiler Optimizations // FOR 64-bit compilers
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <string> // optimizations for 64 bit bitsets
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

// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
using namespace __gnu_pbds;
using namespace std;
#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

// typedef tree<
// 	long long, // Key type
// 	null_type, // Mapped-policy
// 	less<long long>, // Key comparison functor
// 	rb_tree_tag, // Specifies which underlying data structure to use
// 	tree_order_statistics_node_update> // A policy for updating node invariants
// ordered_set;
// for large numbers;

const uint64_t MAXN = 1e8+7;

template<long long N>
struct Sieve {
	bitset<MAXN>is_prime;
    // bool is_prime[MAXN];
    
	constexpr Sieve() : is_prime() {
		is_prime.set();
        // memset(is_prime ,1 ,MAXN);
        
		for (long long i = 2; i*i <= N; i++) 
			if (is_prime[i]) {
				for (long long j = 2 * i; j*j < N; j += i) {
					is_prime[j] = false;
				}
			}
	}
};

/* 
// for c++20
// C++20, non-type template parameter can have any LiteralType (note). 
// In short, it is possible to compile-time compute an instance of 
// any class with a constexpr constructor.
template<Sieve<MAXN> s>
struct SieveWrapper {
    static bool get(long long n) {
        return s.is_prime.test(n);
    }
};
bool _isprime(int x) {
    return SieveWrapper<Sieve<MAXN>{}>::get(x);
}
*/

// for version lower than c++20
bool fast_is_prime(long long n) {
    static constexpr Sieve<MAXN> s;
    return s.is_prime.test(n);
}

signed main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	#ifdef CUST_DEBUG
	cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
	#endif

	return 0;
}
