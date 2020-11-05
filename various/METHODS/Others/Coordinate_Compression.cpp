// coordinate compression
// Coordinate Compression is mainly used to map larger 
//  values to smaller values to remove the vacant space
// https://codeforces.com/blog/entry/84164
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;using namespace __gnu_pbds;

const long long MAXN = 1e6 +7;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31); }
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM); }
};

// gp_hash_table/unordresd map will work too src- cses-1144 submission
map<long long, long long ,custom_hash> M;

vector<long long> b;

// Now every value of an array lies in [0, n). The most convineint it that if you need the original value for a[i], you can just write b[a[i]].
void compress(vector<long long> &a){
	b = a;
	sort(b.begin(), b.end());
	for(int i = 0 ;i < b.size() ;i++){
		M[b[i]] = i;
	}
	for(int i = 0 ; i < b.size() ;i++){
		a[i] = M[a[i]];
	}
}

int32_t main(){
	ll n = 1000000;
	vector<ll> a(n);
	// test 
	iota(ALL(a) ,100000000);
	compress(a);
	return 0;
}