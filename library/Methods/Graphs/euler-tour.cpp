
vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int color[MAXN] ,euler_tree[2*MAXN] ,depth[2*MAXN] ,last[MAXN];
int n ,m ,idx = 0;

void eulerTour(int v = 0 ,int d = 0){
	visited[v] = 1;
	depth[idx] = d;
	last[v] = idx;
	euler_tree[idx++] = v;
	
	for(int u : adj[v]){
		if(!visited[u]){
		    eulerTour(u ,d+1);
		    depth[idx] = d;
		    last[u] = idx-1;
		    euler_tree[idx++] = v;
		}
	}
}
