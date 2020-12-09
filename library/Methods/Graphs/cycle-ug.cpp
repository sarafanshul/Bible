// Cycle dectection in un-directed Graph
// https://cp-algorithms.com/graph/finding-cycle.html
// https://www.youtube.com/watch?v=rKQaZuoUR4M
vector<vector<int>> adj(MAXN ,vector<int>(0));
vector<int> color(MAXN ,0); // all vertices are unvisited
int n, m  ,parent[MAXN]= {-1} ,cycle_start = -1 ,cycle_end = -1;

bool dfs(int v ,int par){
	color[v] = 1;
	for(int u : adj[v]){
		if (u == par) continue;
		if(color[u] == 0){
			parent[u] = v;
			if(dfs(u ,parent[u])) return 1;
		} else if(color[u] == 1){
			cycle_end = v;
			cycle_start = u;
		   	return 1;
		}
	}
	color[v] = 2;
	return 0;
}

void find_cycle(){
	for(int v = 0 ; v <= n; v++){
		if(color[v] == 0 && dfs(v ,parnt[v]) ) break;
	}
	if(cycle_start == -1) {		
		cout << "Acyclic\n";return; 
	}
	vector<int> cycle;
	cycle.reserve(MAXN +1);
	cycle.PB(cycle_start);
	for(int v = cycle_end; v != cycle_start ; v = parent[v]){
		cycle.PB(v);
	}cycle.PB(cycle_start);
	reverse(ALL(cycle));
	cout << "Cycle Found\n";
	for(int v :cycle) cout << v  << " ";
	return;
}

