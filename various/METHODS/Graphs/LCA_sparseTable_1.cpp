#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010; /* Max nodes */
const int M = 30; /* Max LOG */
int LG;
int n;

vector<int> adj[N]; /* Adjacency list */
int p[N][M]; /* Sparse table */
int depth[N];

void init( void ) {
    LG = 0;
    while((1 << LG) < n)
        LG += 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < LG; j++)
            p[i][j] = -1;
}

void dfs(int x, int par = -1, int d = 0) {
    depth[x] = d;

    p[x][0] = par;
    for(int i = 1; i < LG; i++)
        if(p[x][i - 1] + 1)
            p[x][i] = p[p[x][i - 1]][i - 1];

    for(auto y: adj[x])
        if(y != par)
            dfs(y, x, d + 1);
}

int lca(int x, int y) {
    if(depth[x] > depth[y])
        swap(x, y);

    for(int i = LG - 1; i >= 0; i--)
        if((p[y][i] + 1) && (depth[p[y][i]] >= depth[x]))
            y = p[y][i];

    if(x == y)
        return x;

    for(int i = LG - 1; i >= 0; i--)
        if((p[x][i] + 1) && (p[x][i] != p[y][i]))
            x = p[x][i], y = p[y][i];

    return p[x][0];
}

int main( void ) {

    /* Usage example */

    cin >> n;
    for(int i = 0; i < n; i++)
        adj[i].clear();

    for(int i = 0; i < n; i++) {
        int len;

        cin >> len;
        while(len--) {
            int x;

            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    /* Init and pre-process */
    init();
    dfs(0);

    /* Answer queries */
    int q;

    cin >> q;
    while(q--) {
        int x, y;

        cin >> x >> y;
        cout << lca(x, y) << endl;
    }

    return 0;
}