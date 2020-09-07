
/*
// Edmonds Karps
// https://www.youtube.com/watch?v=Xu8jjJnwvxE&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=33
// https://cp-algorithms.com/graph/edmonds_karp.html
// https://www.youtube.com/watch?v=oHy3ddI9X3o
// Edmonds-Karp algorithm is just an implementation of the 
	Ford-Fulkerson method that uses BFS for finding 
	augmenting paths

*/

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
// #define INF INT_MAX
// // for overflow
#define int long long
#define INF LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e3 +7;

vector<vector<int>> adj(MAXN ,vector<int>(0)); // adjacency list of the undirected graph, since we have also to use the reversed of directed edges when we are looking for augmenting paths
int capacity[MAXN][MAXN]; // stores the capacity for every pair of vertices
int n ,m;

int bfs(int s ,int t ,vector<int>& parent){
	fill(ALL(parent) ,-1);
	parent[s] = -2;
	queue<pair<int ,int> > q;
	q.push({s ,INF});

	while(!q.empty()){
		int cur = q.front().F;
		int flow = q.front().S;
		q.pop();
		for(int next : adj[cur]){
			if(parent[next] == -1 && capacity[cur][next]){
				parent[next] = cur;
				int new_flow = min(flow ,capacity[cur][next]);
				if(next == t)
					return new_flow;
				q.push({next ,new_flow});
			}
		}
	}
	return 0;
}

template<typename T = int>
T maxflow(T s ,T t){
	int flow = 0;
	vector<int> parent(n);
	int new_flow ,cur ,prev;

	while(new_flow = bfs(s ,t ,parent)){
		flow += new_flow;
		cur = t;
		while(cur != s){
			prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	memset(capacity ,0 ,sizeof(capacity)); // initial capacity = 0
	int u ,v ,w;
	cin >> n >> m;
	int start = 0 ,sink = n-1;
	while(m--){
		cin >> v >> u >> w;
// 		u--;v--; // for 1 based indexing
		// undirected graph, since we have also to use the reversed of directed edges when we are looking for augmenting paths
		adj[v].PB(u);
		adj[u].PB(v);
		capacity[v][u] = w;
		capacity[u][v] = w;
	}
	int _mx = maxflow(start ,sink);
	cout << _mx;

	return 0;
}
