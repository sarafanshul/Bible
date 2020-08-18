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
const uint32_t MAXN = 1e5+7;

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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int u ,v;
	for(int i = 0; i < m ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	} // root is 1;
	eulerTour();
	// print()
	for(int i = 0 ;i < 2*n-1 ;i++) cout << euler_tree[i] << " ";
	cout << "\n";
	for(int i = 0 ;i < 2*n-1 ;i++) cout << depth[i] << " ";
	cout << "\n";
	for(int i = 0 ;i < n ;i++) cout <<i<<" -> "<< last[i] << "\n";
	return 0;
}