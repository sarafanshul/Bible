#include <bits/stdc++.h>
using namespace std;

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = n-1; i >= 0; --i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main(){
	int m ,a ,b;
	cin >> n >> m;
	adj.assign(n ,vector<int>(0));
	while(m--){
		cin >> a >> b;
		adj[--a].push_back(--b);
	}

	// #for lexicographically smallest one
    // for(int i = 0 ; i < n ;++i) sort(adj[i].begin() ,adj[i].end() ,greater<int>());

	topological_sort();
	
	for(int i = 0; i < n; ++i) cout << ans[i] + 1 << " ";
	
	return 0;
}
