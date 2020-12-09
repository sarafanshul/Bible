//  		Centroid(s) of a tree


// https://codeforces.com/blog/entry/57593
/*

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

https://codeforces.com/contest/1406/problem/C
*/

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };

    dfs(0, -1);
    return centroid;
}
