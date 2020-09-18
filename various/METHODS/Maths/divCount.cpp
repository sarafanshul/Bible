// ######   MAXN = 1e6 only


#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair
#define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;
using namespace __gnu_pbds;

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

const ll MAXN = 1e6 +7;
const ll MOD = 1073741824;//1<<30;

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
gp_hash_table<long long, long long ,custom_hash> _keys; // slower

// ######   MAXN = 1e6 only

bool _hash_t[MAXN];
void pre(){
	memset(_hash_t ,1 ,sizeof(_hash_t));
	for(ll p = 2 ;p*p < MAXN ;p++){
		if(_hash_t[p]){for(ll i = p*2 ; i < MAXN ;i += p){_hash_t[i] = 0;}}
	}
}


ll divCount(ll a){
    if(_keys.find(a) != _keys.end()) return _keys[a];
	ll tot = 1LL ,count = 0;
	for(ll p = 2 ;p <= a; p++){
		if(_hash_t[p]){
			count = 0;
			if(a%p == 0){ while(a%p == 0){ a = a/p;count++; } }
			tot = (tot * (count + 1))%MOD;
		}
	}
	_keys[a] = tot;
	return tot;
}

void check(){
	pre();
	cout << divCount((ll)1e6);
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
