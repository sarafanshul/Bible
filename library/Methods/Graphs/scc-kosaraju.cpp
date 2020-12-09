//  Kosaraju and Sharir Algorithm for SCC
// https://cp-algorithms.com/graph/strongly-connected-components.html
// https://www.youtube.com/watch?v=9Wbej7Fy5Lw
vector<vector<int>> g(MAXN ,vector<int>(0)), gr(MAXN ,vector<int>(0));
vector<bool> used(MAXN ,0);
vector<int> order, component;
int n ,m ,sccCount = 0;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ]) dfs1 (g[v][i]);
	order.push_back (v);
}

// for reverse graph
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ]) dfs2 (gr[v][i]);
}

int32_t main() {

	int a, b;
	cin >> n;
	cin >> m;
	component.reserve(MAXN);
	order.reserve(2*MAXN-1);
	for (int i = 0; i< m ;i++) {
		cin >> a >> b;
		g[a].push_back (b);
		gr[b].push_back (a);
	}

	// topological sort 
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	
	used.assign(n, false);
	// since it is sorted ,If an element appears after v hence cycle(SCC)
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i]; // for stack based ds
		if (!used[v]) {
			dfs2 (v);
			// ... printing next component ...
			for(size_t i = 0 ; i < component.size(); i++){
				cout << component[i] << " ";
			}cout << "\n";
			component.clear();
			sccCount++;
		}
		cout << sccCount <<"\n";
	}
	return 0;
}
