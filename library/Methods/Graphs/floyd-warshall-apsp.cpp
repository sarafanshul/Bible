// Floyd Warshall APSP Algorithm

// use a adjacency matrix { pathfrom [i-i => 0] ,[i-j => input] ,[else Infinite] }
int adj[MAXN][MAXN] ,p[MAXN][MAXN];
int n ,m;

void floydWarshall(){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adj[i][j] != INT_MAX && adj[i][j] != 0) p[i][j] = j; // if distance is not inf then next node from i is j
		}
	}
		
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (adj[i][k] < INT_MAX && adj[k][j] < INT_MAX){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					p[i][j] = p[i][k];
				}
			}
		}
	}

	// negative cycle
	for (int k = 0; k < n; k++){
      	for (int i = 0; i < n; i++){
        	for (int j = 0; j < n; j++){
          		if (adj[i][k] + adj[k][j] < adj[i][j]) {
            		adj[i][j] = INT_MIN;
            		p[i][j] = -1;
          		}
          	}
        }
    }
}

vector<int> retrive_path(int u ,int v){ // not working
	vector<int>path;
	// path.reserve(MAXN);
	if (adj[u][v] == INT_MAX) return path;
	int at = u;
	for(; at != v ; at = p[at][v]){
		if(at == -1) return {};
		path.PB(at);
	}
	if(p[at][v] == -1) return {};
	path.PB(v);
	return path;
}

