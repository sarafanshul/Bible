// Solution to finding the shortest (and longest) path on a Directed Acyclic Graph (DAG) using a topological sort in combination with dynamic programming
// https://www.youtube.com/watch?v=TXkDpqjDMHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=16
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
// #define int long long
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;
bool visited[MAXN] = {false};
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
vector<int> top_sort ,dist(MAXN ,INT_MAX);
int n ,m;

// greater int not working // because it is pair<> LOL//
inline bool compare(const pair<int,int> &a,const pair<int,int> &b) {return (a.first > b.first);} 

void dfs(int v) {
	if(!visited[v]) {
		visited[v] = true;
		for(pair<int ,int> u : adj[v]) dfs(u.F);
		top_sort.push_back(v);
	}
}

void topological_sort(){
	for(int i=0 ;i <= n ;i++) {sort(adj[i].begin() ,adj[i].end() ,greater<pair<int ,int>>());}
	for(int j=n ;j >= 1 ;j--) {if(!visited[j]) dfs(j);}
	reverse(ALL(top_sort));
	// cout << top_sort.size() << "\n";
	// for(int i = 0; i < n ; i++) cout << top_sort[i] << " ";
	// cout << "\n";
}

void dagShortestPath(int start){
	dist[start] = 0;
	int node_idx ,newDist;
	for(int i = 0 ; i < n; i++){
		node_idx = top_sort[i];
		if(dist[node_idx] != INT_MAX){
			for(pair<int ,int> u : adj[node_idx]){
				newDist = dist[node_idx] + u.S;
				if(dist[u.F] == INT_MAX) dist[u.F] = newDist;
				else dist[u.F] = min(dist[u.F] ,newDist);
			}
		}
	}
	// for(int i = 1; i <= n ; i++) cout << i << " -> " << dist[i] << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	top_sort.reserve(MAXN);
	int u ,v ,d;
	cin>>n;
	cin>>m;
	while(m--) {
		cin>>u>>v>>d;
		adj[u].push_back(MP(v ,d)); // DAG
	}
	topological_sort();
	dagShortestPath(1);
	
	return 0;
}
