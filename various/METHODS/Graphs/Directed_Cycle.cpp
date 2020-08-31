// Cycle dectection in Directed Graph
// https://cp-algorithms.com/graph/finding-cycle.html
// https://www.youtube.com/watch?v=rKQaZuoUR4M
//
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
#define int long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;
vector<vector<int>> adj(MAXN ,vector<int>(0));
vector<int> color(MAXN ,0); // all vertices are unvisited
int n, m  ,parent[MAXN]= {-1} ,cycle_start = -1 ,cycle_end = -1;

bool dfs(int v){
	color[v] = 1; // being visited 
	for(int u :adj[v]){
		if(color[u] == 0){ // completly unvisited(undiscovered) vertice
			parent[u] = v; // parent map
			if(dfs(u)) return 1;
		}
		else if(color[u] == 1){ // vertice currently being visitede but still discovered (cycle found)
			cycle_end = v;
			cycle_start = u;
			return 1;	
		}
	}
	color[v] = 2; // fully visited vertice
	return 0;
}

void find_cycle(){
	for(int v = 0; v <= n ; v++){
		if(color[v] == 0 && dfs(v))
			break;
	}
	if(cycle_start == -1) {
		cout << "Acyclic" << "\n";return;
	}
	vector<int> cycle;
	cycle.reserve(MAXN + 1);
	cycle.PB(cycle_start);
	for(int v = cycle_end ; v != cycle_start ; v = parent[v]){
		cycle.PB(v);
	}
	cycle.PB(cycle_start);
	reverse(ALL(cycle));
	cout << "Cycle found:\n";
	for(int v : cycle) cout << v << " ";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	cin >> n;
	cin >> m;
	int u  ,v;
	for(int i = 0; i <m ;i++){
		cin >> u >> v;
		adj[u].PB(v);
	}

	find_cycle();

	return 0;
}
