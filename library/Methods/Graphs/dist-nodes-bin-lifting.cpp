// https://cp-algorithms.com/graph/lca_binary_lifting.html
// https://www.youtube.com/watch?v=MOy4UDjN8DM&list=PLZU0kmvryb_HZpDW2yfn-H-RxAu_ts6xq&index=10&t=1508s
//
// for distance between two nodes we will se lca of two nodes
// 		if LCA(n1 ,n2) = a;
// 		distance between n1 - n2 = h(n1 - a) + h(n2 - a)
// 			(where h is the height array)

int n, l;
vector<vector<int>> adj(MAXN ,vector<int>(0));

int timer;
vector<int> tin, tout ,h;
vector<vector<int>> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    h[v] = h[p]+1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
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

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    h.resize(n);
    h[root] = 0;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int dist(int u ,int v){
    int _lca = lca(u ,v);
    return (h[u] - h[_lca]) + (h[v] - h[_lca]);
}

void check(){
	int m ,q ,u ,v;
	cin >> n >> m;
	for(int i = 0 ;i < m ; i++){ // 0 based
		cin >> u >> v;u--;v--;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	preprocess(0);
	cin >> q;
	for(int i = 0; i < q ;i++){
		cin >> u >> v;u--;v--;
		cout << dist(u ,v) << "\n"; 
	}
}
