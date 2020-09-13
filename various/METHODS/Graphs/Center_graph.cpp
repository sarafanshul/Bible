// Center of tree

/*// https://stackoverflow.com/questions/27994552/finding-the-center-of-the-diameter-of-a-graphtree-using-bfs

center is always the middle vertex or middle two vertices in every longest path along the tree
*/
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
#define INF INT_MAX

using namespace std;

const int MAXn = 1007 ,MAXm = 1001;


// ===== not working use dfs one :( ======
pair<int, int> biggest_dist(int n, int v, vector< vector<int> >& graph){
    vector<int> dist(n, INF);
    vector<int> prev(n, INF);

    dist[v] = 0;
    queue<int> next;
    next.push(v);

    int bdist = 0; //biggest distance
    int lastV = v;
    while (!next.empty()) {
        int pos = next.front();
        next.pop();
        bdist = dist[pos];
        lastV = pos;

        for (int i = 0; i < graph[pos].size(); ++i) {
            int nghbr = graph[pos][i];
            if (dist[nghbr] > dist[pos] + 1) {
                dist[nghbr] = dist[pos] + 1;
                prev[nghbr] = pos;
                next.push(nghbr);
            }
        }
    }

    int center = lastV;
    for (int i = 0; i + i < bdist; ++ i) center = prev[center];

    return make_pair(lastV, center); 
}

int getCenter(int n, vector< vector<int> >& graph){
    // first call is to get the vertex that is furthest away from vertex 0, where 0 is just an arbitrary vertes
    pair<int, int> firstResult = biggest_dist(n, 0, graph);
    // second call is to find the vertex that is furthest away from the vertex just found
    pair<int, int> secondResult = biggest_dist(n, firstResult.first, graph);
    return secondResult.second+1;// 0 based indexing idk
}

void check(){
	int n ,m ,q ,u ,v;
	cin >> n;
	vector<vector<int>> adj;
	adj.resize(n);
	cin >> m;
	for(int i = 0 ;i < n ; i++){ // 0 based indexing
		cin >> u >> v; u--;v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}

	cout << getCenter(n ,adj) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for(int c = 0 ; c < t ; c++){
		cout << "Case " << c+1 << ":\n";
		check();
	}
	return 0;
}