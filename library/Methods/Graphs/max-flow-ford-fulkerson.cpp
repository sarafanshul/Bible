/*// Edmonds Karps
// https://www.youtube.com/watch?v=Xu8jjJnwvxE&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=33
// https://cp-algorithms.com/graph/edmonds_karp.html
// https://www.youtube.com/watch?v=oHy3ddI9X3o
// Edmonds-Karp algorithm is just an implementation of the 
	Ford-Fulkerson method that uses BFS for finding 
	augmenting paths*/

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
	// memset(capacity ,0 ,sizeof(capacity)); // initial capacity = 0
	// int start = 0 ,sink = n-1;
	// 	adj[v].PB(u);
	// 	adj[u].PB(v);
	// 	capacity[v][u] = w;
	// 	capacity[u][v] = w;
	// int _mx = maxflow(start ,sink);

