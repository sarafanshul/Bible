#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define TEST(s) if (!(s)) { cout << __LINE__ << " " << #s << endl; exit(-1); }

struct tree {
  	int n;
  	vector<vector<int>> adj;
  	tree(int n) : n(n), adj(n) { }
  	void add_edge(int s, int t) {
		adj[s].push_back(t);
		adj[t].push_back(s);
  	}
  	vector<int> pos, tour, depth;
  	vector<vector<int>> table;
  	int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }
  	void rootify(int r) {
		pos.resize(n);
		function<void (int,int,int)> dfs = [&](int u, int p, int d) {
	  	pos[u] = depth.size();
	  	tour.push_back(u);
	  	depth.push_back(d);
	  	for (int v: adj[u]) {
			if (v != p) {
		  		dfs(v, u, d+1);
		  		tour.push_back(u);
		  		depth.push_back(d);
			}
	  	}
		}; dfs(r, r, 0);
		int logn = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(tour.size()); // log2
		table.resize(logn+1, vector<int>(tour.size()));
		iota(all(table[0]), 0);
		for (int h = 0; h < logn; ++h) 
	  	for (int i = 0; i+(1<<h) < tour.size(); ++i)
			table[h+1][i] = argmin(table[h][i], table[h][i+(1<<h)]);
  	}
  	int lca(int u, int v) {
		int i = pos[u], j = pos[v]; if (i > j) swap(i, j);
		int h = sizeof(int)*__CHAR_BIT__-1-__builtin_clz(j-i); // = log2
		return i == j ? u : tour[argmin(table[h][i], table[h][j-(1<<h)])];
  	}
};

void ck() {
  int n;
  scanf("%d", &n);
  tree T(n);
  for (int u = 0; u < n ; ++u) {
	int k; 
	scanf("%d", &k);
	for (int j = 0; j < k; ++j) {
	  int v;
	  scanf("%d", &v);
	  T.add_edge(u, --v);
	}
  }
  T.rootify(0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
	int u, v;
	scanf("%d %d", &u, &v);
	printf("%d\n", T.lca(--u, --v)+1);
  }
}

int main(){
	int t = 0;
	scanf("%d" ,&t);
	for(int i = 1; i <= t ;i++){
		printf("Case %d:\n" ,i);
		ck();
	}
	return 0;
}