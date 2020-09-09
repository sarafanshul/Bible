// coordinate compression
// Coordinate Compression is mainly used to map larger 
//  values to smaller values to remove the vacant space

// https://www.quora.com/What-is-coordinate-compression-and-what-is-it-used-for


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

const uint64_t RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    size_t operator()(uint64_t x) const { return x ^ RANDOM; }
};

// gp_hash_table<long long, long long ,custom_hash> _keys ,_orig; // slower
gp_hash_table<long long, long long ,chash> _keys ,_orig; // faster (less secure)


long long idx = 1;

template<class T = vector<long long>>
void _store(T &v){
    sort(ALL(v));
    for(size_t i = 0 ; i < v.size() ; i++){
        if( _keys.find(v[i]) == _keys.end() ){
            _keys[v[i]] = idx; // for storing compression
            _orig[idx] = v[i]; // for searching back
            idx++;
        }
    }
}

template<class T = vector<long long>>
void _extract(T &a){
    for(size_t i = 0; i < a.size(); i++){a[i] = _keys[a[i]];}
}

template<class T = vector<long long>>
void _compress(T &v , T &a){
    _store(v); _extract(a); // {a ∈ v} 
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin.exceptions(cin.failbit);
    ll n = 1000000;
    vector<ll> a(n);
    iota(ALL(a) ,100000000);
    _compress(a ,a);
    return 0;
}