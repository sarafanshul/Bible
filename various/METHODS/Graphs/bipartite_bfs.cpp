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

void isBipartite_bfs(){
	bool ok = 1;
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			queue<int> q;
			q.push(i);
			color[i] = 1;
			while(!q.empty()){
				u = q.front();q.pop();
				int z = color[u]%2 + 1;
				for(int v : adj[u]){
					if (!color[v]) {q.push(v);color[v] = z;}
					else if (z != color[v]){ok = 0; break;}
				}
			}
		}
	}
	if(!ok){cout<<"IMPOSSIBLE\n"; return 0;}
	for(int i = 1 ; i <= n ;++i) cout << color[i] << " ";
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
	isBipartite_bfs();
	return 0;
}