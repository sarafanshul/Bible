#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
#define MP make_pair

using namespace std;

const int MAXn = 1007 ,MAXm = 1001;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

inline bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

inline void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}


void check(){
	cin >> n;
	int n ,m ,q ,u ,v;
	adj.resize(n);
	for(int i = 0 ;i < n ; i++){ // 0 based
		cin >> u >> v;u--;v--;
		adj[v].PB(u);
		adj[u].PB(v);
		
	}
	// --- preprocess ----
	preprocess(0);
	
	cin >> q;
	for(int i = 0; i < q ;i++){
		cin >> u >> v;u--;v--;
		cout << lca(u ,v)+1 << "\n"; 
	}
	adj.clear();
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for(int c = 0 ; c < t ; c++){
		cout << "Case " << c << ":\n";
		check();
	}
	return 0;
}