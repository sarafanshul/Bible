//// ############ NOT THROUGHLY TESTED ##############


/*// https://stackoverflow.com/questions/27994552/finding-the-center-of-the-diameter-of-a-graphtree-using-bfs

// Using BFS

// for Diameter
To compute the diameter of a tree, you need first to 
 choose an arbitrary vertex (let's say v), then find the vertex that is 
 furthest away from v (let's say w), and then find a vertex that is 
 furthest away from w, let's sat u. 
 The distance between w and u is the diameter of the tree.

// for Center
To make it actually find the center, 
 you can also remember the parent for each node 
 during your BFS. To do so, allocate an extra 
 array, say prev, and when you do
	dist[nghbr] = dist[pos] + 1;
also do
	prev[nghbr] = pos;

Then at the end of the second call to the function, 
 you can just descend bdist/2 times into the prev, something like:

	center = lastVertex;
	for (int i = 0; i + i < bdist; ++ i) center = prev[center];
	
//// ############ NOT THROUGHLY TESTED ##############
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

pair<int, int> biggest_dist(int n, int v, vector< vector<int> >& graph) {
	// int INF = 2 * graph.size(); // Bigger than any other length
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
	return make_pair(lastV, bdist);
}

int getDiameter(int n, vector< vector<int> >& graph){
	pair<int, int> firstResult = biggest_dist(n, 0, graph);
	// second call is to find the vertex that is furthest away from the vertex just found
	pair<int, int> secondResult = biggest_dist(n, firstResult.first, graph);
	return secondResult.second + 1; // idk here :()
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

	cout << getDiameter(n ,adj) << "\n";
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