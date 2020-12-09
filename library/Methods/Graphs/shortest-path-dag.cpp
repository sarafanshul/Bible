// Solution to finding the shortest (and longest) path on a Directed Acyclic Graph (DAG) using a topological sort in combination with dynamic programming
// https://www.youtube.com/watch?v=TXkDpqjDMHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=16

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
	topological_sort();
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
