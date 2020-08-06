#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

const uint32_t MOD = 1e9+7;
const uint32_t MAXN = 1e7+7;
int n ,m;

vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int color[MAXN];

bool isBipartite(int v){
	visited[v] = 1;
	for(int u :adj[v]){
		if (!visited[u]){
			color[u] = !color[v];
			if(!isBipartite(u)) return false;
		}
		else if (color[u] == color[v]) return false;
	}
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int u ,v;
	for(int i = 0; i < m ;i++){
		cin >> u>>v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	color[1] = 0;
	if (! isBipartite(1)){cout << "IMPOSSIBLE";return 0;}
	for(int i = 1; i <= n ;++i){
		cout << color[i]+1<<" ";
	}

	return 0;
}