// Centriod Decomposition 
/*

https://www.youtube.com/watch?v=3pk02p1-weU

https://www.youtube.com/watch?v=2izuGA8T8IE
https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
https://petr-mitrichev.blogspot.com/2015/03/this-week-in-competitive-programming_22.html
https://ipsc.ksp.sk/2009/real/solutions/l.html
*/

void calc_sizes(const vector<vector<int>> &tree, vector<int> &size, vector<bool> &deleted, int u, int p) {
    size[u] = 1;
    for (int v : tree[u]) {
        if (v == p || deleted[v])
            continue;
        calc_sizes(tree, size, deleted, v, u);
        size[u] += size[v];
    }
}

int find_tree_centroid(const vector<vector<int>> &tree, vector<int> &size, vector<bool> &deleted, int u, int p,
                       int vertices) {
    for (int v : tree[u]) {
        if (v == p || deleted[v])
            continue;
        if (size[v] > vertices / 2) {
            return find_tree_centroid(tree, size, deleted, v, u, vertices);
        }
    }
    return u;
}

// void dfs(const vector<vector<int>> &tree, vector<bool> &deleted, int u, int p) {
//     for (int v: tree[u]) {
//         if (v == p || deleted[v])continue;
//         dfs(tree, deleted, v, u);
//     }
// }

void decompose(const vector<vector<int>> &tree, vector<int> &size, vector<bool> &deleted, int u, int total) {
    calc_sizes(tree, size, deleted, u, -1);
    int centroid = find_tree_centroid(tree, size, deleted, u, -1, total);
    deleted[centroid] = true;

    // process centroid vertex here
    // dfs(tree, deleted, centroid, -1);
    cout << centroid << "\n";

    for (int v : tree[centroid]) {
        if (deleted[v])
            continue;
        decompose(tree, size, deleted, v, size[v]);
    }
}

void test(){
	vector<vector<int>> tree = {{3}, {3}, {3}, {0, 1, 2}};

    int n = tree.size();
    vector<int> size(n);
    vector<bool> deleted(n);
    decompose(tree, size, deleted, 0, n);
}
