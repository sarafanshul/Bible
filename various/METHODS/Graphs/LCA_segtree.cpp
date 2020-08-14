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

struct LCA {
	vector<int> height, euler, first, segtree;
	vector<bool> visited;
	int n;

	LCA(vector<vector<int>> &adj, int root = 0) {
		n = adj.size();
		height.resize(n);
		first.resize(n);
		euler.reserve(n * 2);
		visited.assign(n, false);
		dfs(adj, root);
		int m = euler.size();
		segtree.resize(m * 4);
		build(1, 0, m - 1);
	}

	void dfs(vector<vector<int>> &adj, int node, int h = 0) {
		visited[node] = true;
		height[node] = h;
		first[node] = euler.size();
		euler.push_back(node);
		for (auto to : adj[node]) {
			if (!visited[to]) {
				dfs(adj, to, h + 1);
				euler.push_back(node);
			}
		}
	}

	void build(int node, int b, int e) {
		if (b == e) {
			segtree[node] = euler[b];
		} else {
			int mid = (b + e) / 2;
			build(node << 1, b, mid);
			build(node << 1 | 1, mid + 1, e);
			int l = segtree[node << 1], r = segtree[node << 1 | 1];
			segtree[node] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int node, int b, int e, int L, int R) {
		if (b > R || e < L)
			return -1;
		if (b >= L && e <= R)
			return segtree[node];
		int mid = (b + e) >> 1;

		int left = query(node << 1, b, mid, L, R);
		int right = query(node << 1 | 1, mid + 1, e, L, R);
		if (left == -1) return right;
		if (right == -1) return left;
		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		if (u == v) return u;
		int left = first[u], right = first[v];
		if (left > right)
			swap(left, right);
		return query(1, 0, euler.size() - 1, left, right);
	}
};


void check(){
	cin >> n;
	int n ,m ,q ,u ,v;
	vector<vector<int>> adj;
	adj.resize(n);
	for(int i = 0 ;i < n ; i++){
		cin >> m;
		while(m--){
			cin >> u;u--; // 1 based indexing
			adj[i].PB(u);
			adj[u].PB(i);
		}
	}
	// --- feed the adj list to the constructor ----
	LCA _lca(adj);
	cin >> q;
	for(int i = 0; i < q ;i++){
		cin >> u >> v;u--;v--;
		cout << _lca.lca(u ,v)+1 << "\n"; 
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