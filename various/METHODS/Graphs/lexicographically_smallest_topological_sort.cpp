
/*
this can be easily done using with bfs but if some one wants to try with dfs.
there is two imp point
1 sort all adjacency list in descending order.
2 when apply calling of dfs function iterate vertes in descending order.

*/

#include <bits/stdc++.h>
using namespace std;

bool _visit[10000] = {false};

void dfs(vector<int> adj[] ,int n ,vector<int> &ans) {
	if(!_visit[n]) {
		_visit[n] = true;
		for(int i=0;i<adj[n].size();i++) dfs(adj,adj[n][i] ,ans);
		ans.push_back(n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int n ,m ,x ,y;
	cin>>n;
	vector<int> adj[n+1];
	vector<int> ans;
	memset(_visit ,false ,sizeof(_visit));
	cin>>m;

	while(m--) {
		cin>>x>>y;
		adj[x].push_back(y);
	}

	for(int i=0 ;i <= n ;i++) {
		sort(adj[i].begin() ,adj[i].end() ,greater<int>());
	}

	for(int j=n ;j >= 1 ;j--) {
		if(! _visit[j]) dfs(adj ,j ,ans);
	}

	for(int j = n-1 ;j >= 0 ;j--) {
		cout<<ans[j]<<" ";
	}
	return 0;
}