

// Algorithm for Eulerian Path/Circut for an Undirected Graph
// O(m)
//  ===== FOR UN-DIRECTED GRAPH =====

// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define INT_MAX LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;
vector<vector<int>> adj(MAXN ,vector<int>(0));
bool visited[MAXN] = {0};
vector<int> indeg(MAXN ,0) ,outdeg(MAXN ,0) ,path(MAXN);
int n ,m ,start_node = -1 ,end_node;
bool has_path = false;

void dfs(int v){
	visited[v] = 1;
	for(int u : adj[v])
		if(!visited[u])
			dfs(u);
}

bool isConnected(){
	int v;
	for(int v = 0; v <= n ;v++)
		if((int)adj[v].size() != 0)
			break;
	if(v == n) return 1;

	dfs(v);

	for(int i = 0; i <= n ;i++){
		if(!visited[i] && adj[i].size())
			return 0;
	}
	return 1;
}

uint32_t isEulerian(){
	if(! isConnected()) return 0;
	int odd = 0;
	for(int i = 0; i <= n ;i++)
		if((int)adj[i].size() & 1)
			odd++;
	if(odd > 2) return 0;
	return (odd) ? 1 : 2;
}

void check(){
	int res = isEulerian(); 
    if (res == 0) cout << "graph is not Eulerian\n"; 
    else if (res == 1) cout << "graph has a Euler path\n"; 
    else cout << "graph has a Euler cycle\n"; 
    // not working
// 	if(res){
// 		for(size_t i = 0; i < path.size() ; ++i) cout << path[i] << " -> ";
// 		cout << "\n";
// 	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	path.reserve(2*MAXN);
	int u ,v;
	cin >> n;cin >> m;
	for(int i = 0 ;i < m; i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	check();
	return 0;
}
