// Cycle dectection in Directed Graph
// https://cp-algorithms.com/graph/finding-cycle.html
// https://www.youtube.com/watch?v=rKQaZuoUR4M
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

//	find_cycle();
