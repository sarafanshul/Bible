// coordinate compression
// Coordinate Compression is mainly used to map larger 
// 	values to smaller values to remove the vacant space

// https://www.quora.com/What-is-coordinate-compression-and-what-is-it-used-for


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
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;

// FOR LONG LONG INTS (for unhackable hashing)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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

unordered_map< long long, long long, custom_hash> _keys ,_orig;

long long idx = 1;

void _compress(vector<long long> &a){
	sort(ALL(a));
	for(size_t i = 0 ; i < a.size() ; i++){
		if( _keys.find(a[i]) == _keys.end() ){
			_keys[a[i]] = idx; // for storing compression
			_orig[idx] = a[i]; // for searching back
			idx++;
		}
	}
	for(size_t i = 0; i < a.szie(); i++){
		a[i] = _keys[a[i]]; // for appliting compression
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);

	return 0;
}
