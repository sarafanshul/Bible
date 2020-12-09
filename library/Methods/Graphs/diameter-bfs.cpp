// diameter of a tree using BFS

vector<long long> adj[MAXN];
long long dist[MAXN];
bool visited[MAXN];
int n ,m;

void bfs(long long v) {
	memset(dist ,-1 ,sizeof(dist));
	dist[v] = 0;
	queue<long long> q;
	q.push(v);
	long long u;
	while(!q.empty()){
		v = q.front();q.pop();
		for(long long u :adj[v]){
			if(dist[u] == -1){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
} 

pair<long long ,long long> farthest(){
	long long _max = -1 ,node = -1;
	for(int i = 0 ;i <= n ;i++) 
		if(dist[i] > _max) {_max = dist[i];node = i;}
	return MP(node ,_max);
}


	// bfs(0);
	// pair<long long ,long long> last = farthest();
	// bfs(last.F);
	// long long max_d = farthest().S;
