// topological sort khan's Algorithm 
// priority_queue -> (lexicographically sorted)->O(Vlog(V) + E)
// queue -> simple -> O(V+E)
//change the queue to priority queue for lexicographically sorted order
//

// for priority queue workround |
// http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/#:~:text=Instead%20of%20a%20strict%20FIFO,one%20with%20the%20highest%20priority.&text=A%20user%2Dprovided%20compare%20can,appear%20as%20the%20top().

vector<vector<int>> adj(MAXN ,vector<int>(0));
vector<int> indeg(MAXN ,0) ,top_sort;
int n ,m;

int32_t main() {

	int a, b;
	cin >> n;
	cin >> m;
	for (int i = 0; i< m ;i++) {
		cin >> a >> b;
		a--;b--; // 0 based indexing
		adj[a].push_back(b); // DAG
		indeg[b]++;
	}
	priority_queue<int ,vector<int> ,greater<int> > q;
	for(int i = 0; i < n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.top();q.pop();
		top_sort.PB(v+1);
		for(int u :adj[v]){
			indeg[u]--;
			if(indeg[u] == 0){q.push(u);}
		}
	}
	for(size_t i = 0 ;i < top_sort.size(); i++){cout << top_sort[i] << " ";}
	cout << "\n";
	return 0;
}

