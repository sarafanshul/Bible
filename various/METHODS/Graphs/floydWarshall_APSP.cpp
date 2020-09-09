// Floyd Warshall APSP Algorithm

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
// #define int long long
// #define INT_MAX LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN
#define MP make_pair

using namespace std;
const size_t MAXN = 1e3 +7;

// use a adjacency matrix { pathfrom [i-i => 0] ,[i-j => input] ,[else Infinite] }
int adj[MAXN][MAXN] ,p[MAXN][MAXN];
int n ,m;

void floydWarshall(){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adj[i][j] != INT_MAX && adj[i][j] != 0) p[i][j] = j; // if distance is not inf then next node from i is j
		}
	}
		
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (adj[i][k] < INT_MAX && adj[k][j] < INT_MAX){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					p[i][j] = p[i][k];
				}
			}
		}
	}

	// negative cycle
	for (int k = 0; k < n; k++){
      	for (int i = 0; i < n; i++){
        	for (int j = 0; j < n; j++){
          		if (adj[i][k] + adj[k][j] < adj[i][j]) {
            		adj[i][j] = INT_MIN;
            		p[i][j] = -1;
          		}
          	}
        }
    }
}

vector<int> retrive_path(int u ,int v){ // not working
	vector<int>path;
	// path.reserve(MAXN);
	if (adj[u][v] == INT_MAX) return path;
	int at = u;
	for(; at != v ; at = p[at][v]){
		if(at == -1) return {};
		path.PB(at);
	}
	if(p[at][v] == -1) return {};
	path.PB(v);
	return path;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(adj ,INT_MAX ,sizeof(adj));
	memset(p ,-1 ,sizeof(p));
	for(int i = 0 ;i < MAXN ;i++) adj[i][i] = 0;

	int u ,v ,w;
	cin>>n;
	cin>>m;
	while(m--) {
		cin>>u>>v>>w;
		adj[u][v] = w; // DAG
	}

	floydWarshall();
	vector<int>path;
	cin >> u >> v;
	path = retrive_path(u , v);
	cout << path.size() << "\n";
	for(size_t i = 0; i < path.size() ;i++ ) cout << path[i] << "- ";
	return 0;
}
