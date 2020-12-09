/*

// https://codeforces.com/blog/entry/57593
pre - Centroid of a tree
./Centroid_tree.cpp

You may sometimes want to find the centroids of any subtree by cutting the original tree. When cutting a tree, you don't really 'cut' the tree. Instead, just make the vertice die. By ignoring died vertices, you can re-implement the Centroid function like this way.

*/

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
