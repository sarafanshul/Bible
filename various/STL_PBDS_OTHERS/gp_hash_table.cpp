
// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;
using namespace __gnu_pbds;

// global declerations
const size_t MAXN = 1e5 +7;


// ============================================= //

// hash 1
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<long long, long long ,custom_hash> _keys ,_orig; // slower

inline void _add(ll x ,ll val){
	if(_keys.find(x) == _add.end()) _add[x] = 0LL;
	_keys[x] += val;
}

// for pairs
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};
gp_hash_table<pair<long long, long long> ,long long, long long ,custom_hash> _keys ,_orig; // slower

// =====================================================================

// same as below but not prone to powers of 2; speed = mid
const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;
struct chash1{
    ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
};
gp_hash_table<long long, long long ,chash1> _keys ,_orig;


// bellow is prone to powers of two, so, hash function does not help //

// hash 2 somewhat faster but prone to powers of t0
const uint64_t RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    size_t operator()(uint64_t x) const { return x ^ RANDOM; }
};
gp_hash_table<long long, long long ,chash> _keys ,_orig; // faster [{(less secure)}]


// for pairs
struct chash {
    size_t operator()(pair<long long ,long long> x) const { return x.first* 31 + x.second; }
};
gp_hash_table<pair<long long ,long long>, long long, chash> table;

// ========================================================


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin.exceptions(cin.failbit);

    return 0;
}