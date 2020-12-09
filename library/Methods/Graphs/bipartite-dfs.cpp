vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int color[MAXN];

bool isBipartite(int v){
	visited[v] = 1;
	for(int u :adj[v]){
		if (!visited[u]){
			color[u] = !color[v];
			if(!isBipartite(u)) return false;
		}
		else if (color[u] == color[v]) return false;
	}
	return true;
}

// isBipartite(1)