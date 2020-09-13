//  		Centroid(s) of a tree


// https://codeforces.com/blog/entry/57593
/*

	"By the way, when you do Centroid Decomposition, you don't need to know 2 centroids of the tree. Therefore, if you just want to find 'a' centroid of a dynamic tree, you can implement this in the following way:"


-> for deleting  the centroid (1step towards decomposiotion)
		./ Centroid_Node_Dead.cpp

`Centroid of a Tree is a node which if 
removed from the tree would split it into a ‘forest’, 
such that any tree in the forest would have 
at most half the number of vertices 
in the original tree. ~ GeeksForGeeks`

	The centroid(s) of a tree is, the vertice(s) whose all subtrees' size is not more than n(the size of the whole tree).

	-> A tree may have one centroid or may have two centroids. If it has two centroids, they are always connected (otherwise, the tree can't have n vertices).

	-> You can find these vertices by checking the size of each subtree, doing DFS. When the size of a subtree is s, the size of the other part is n - s.

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


int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
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
    function<int (int, int)> dfs = [&](int u, int prev) {
        for (auto v : g[u]) if (v != prev && !dead[v]) {
            if (sz[v] > n / 2) {
                return dfs(v, u);
            }
        }
        return u;
    };
    return dfs(root, -1);
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
	bool dead(n ,0);
	// declare the dead node first
	int centroid = OneCentroid(root ,g ,dead);

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
