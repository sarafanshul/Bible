// https://cp-algorithms.com/graph/dijkstra.html

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;
bool u[MAXN] = {false};
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
vector<int> top_sort ,d(MAXN ,INT_MAX) ,p(MAXN ,-1);
int n ,m;

void dijkstra(int s) {
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		if (d[v] == INT_MAX)
			break;

		u[v] = true;
		for (pair<int ,int> edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
// 	for(int i = 1; i <= n ;i++) cout << i << "->" << d[i] <<"\n";
}

vector<int> restore_path(int s, int t) {
    vector<int> path;
    path.reserve(MAXN);
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    // for(int i :path) cout << i<< '-';
    return path;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int u ,v ,w;
	cin>>n;
	cin>>m;
	while(m--) {
		cin>>u>>v>>w;
		adj[u].push_back(MP(v ,w)); // DAG
	}
	dijkstra(1);
	vector<int> p = restore_path(1 ,6);
	
	return 0;
}
