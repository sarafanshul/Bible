// Centriod Decomposition 

/*
// https://www.youtube.com/watch?v=3pk02p1-weU 
https://ipsc.ksp.sk/2009/real/solutions/l.html
// https://codeforces.com/blog/entry/57593
pre - Centroid of a tree
./Centroid_tree.cpp

// https://codeforces.com/blog/entry/58025

	This works following way:

	1-> Calculate on the entire tree. All the vertices are alive now.

	2-> Find the centroid of the current tree, and make it die.

	3-> Calculate on the subtree which doesn't include the centroid. Go to 2 with this subtree.

	4-> Calculate something required which includes the centroid.

	5-> Make the centroid alive again, because this is DFS.

Simply enough, when you use this, you just need to change the part 4. All the other parts are the same, which means you can use it generally.
*/

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

void CentroidDecomposition(const vector<vector<int>> &g) {
    int n = (int) g.size();
    vector<bool> dead(n, false);
    function<void (int)> rec = [&](int start) {
        int c = OneCentroid(start, g, dead);            //2
        dead[c] = true;                                 //2
        for (auto u : g[c]) if (!dead[u]) {
            rec(u);                                		//3
        }
        /*
            compute something with the centroid    		//4
        */
        dead[c] = false;                               	//5
    };
    rec(0);                                             //1
}

void test() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    CentroidDecomposition(g);
}
