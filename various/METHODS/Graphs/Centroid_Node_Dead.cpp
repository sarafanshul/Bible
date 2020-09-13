/*

// https://codeforces.com/blog/entry/57593
pre - Centroid of a tree
./Centroid_tree.cpp

You may sometimes want to find the centroids of any subtree by cutting the original tree. When cutting a tree, you don't really 'cut' the tree. Instead, just make the vertice die. By ignoring died vertices, you can re-implement the Centroid function like this way.

*/

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 1e5 +7;

//Don't forget to reuse sz, or it's going to be slow (or if you like, use map).
vector<int> Centroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
    static vector<int> sz(g.size());
    function<void (int, int)> get_sz = [&](int u, int prev) {
        sz[u] = 1;
        for (auto v : g[u]) if (v != prev && !dead[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    };
    get_sz(root, -1);
    int n = sz[root];
    vector<int> centroid;
    function<void (int, int)> dfs = [&](int u, int prev) {
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev && !dead[v]) {
            dfs(v, u);
            if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(root, -1);
    return centroid;
}


void test(){
	int n ,u ,v;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 0; i < n-1 ;i++){
		cin >> u>> v;u-- ,v--;
		g[u].PB(v);
		g[v].PB(u);
	}
	vector<bool> dead(n ,0);
	// declare the dead node first
	vector<int> centroids = Centroid(root ,g ,dead);

	if (centroids.size() == 1) {
	    int c = centroids[0];
	} 
	else if (centroids.size() == 2) {
	    int c1 = centroids[0];
	    int c2 = centroids[1];
	} 
	else {
        assert(false);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	return 0;
}
