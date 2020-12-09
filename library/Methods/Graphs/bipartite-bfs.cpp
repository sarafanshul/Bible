vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int color[MAXN];

void isBipartite_bfs(){
	bool ok = 1;
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			queue<int> q;
			q.push(i);
			color[i] = 1;
			while(!q.empty()){
				u = q.front();q.pop();
				int z = color[u]%2 + 1;
				for(int v : adj[u]){
					if (!color[v]) {q.push(v);color[v] = z;}
					else if (z != color[v]){ok = 0; break;}
				}
			}
		}
	}
	if(!ok){cout<<"IMPOSSIBLE\n"; return 0;}
	for(int i = 1 ; i <= n ;++i) cout << color[i] << " ";
}

	// isBipartite_bfs();
