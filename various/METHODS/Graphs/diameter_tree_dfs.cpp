/*

// Using DFS

// for Diameter
To compute the diameter of a tree, you need first to 
 choose an arbitrary vertex (let's say v), then find the vertex that is 
 furthest away from v (let's say w), and then find a vertex that is 
 furthest away from w, let's sat u. 
 The distance between w and u is the diameter of the tree.

// WORKING PROPERLY
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
const uint64_t MAXN = 1e5 + 7;

vector<int> adj[MAXN];
int n ,m;
bool visited[MAXN];

int x;
void dfsUtil(int v ,int count ,int& maxCount){
	visited[v] = 1;
	count++;
	for(int u : adj[v]){
		if(!visited[u]){
			if(count >= maxCount){
				maxCount = count;
				x = u;
			}
			dfsUtil(u ,count ,maxCount);
		}
	}
}

void dfs(int v ,int& maxCount){
	memset(visited ,0 ,sizeof(visited));
	int count = 0;
	dfsUtil(v ,count + 1 ,maxCount);
}
 
int diameter(int v){
	int maxCount= INT_MIN;
	dfs(v ,maxCount);
	dfs(x ,maxCount);
	return maxCount;
}
 	
void check(){
	int q ,u ,v;
	cin >> n;
	cin >> m;
	for(int i = 0 ;i < m ; i++){ // 0 based indexing
		cin >> u >> v; u--;v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}

	cout << diameter(0) << "\n";
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
