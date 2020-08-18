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
const uint32_t MAXN = 105000;
const uint32_t MAXLOG = 20;
// euler tour
vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int color[MAXN] ,euler_tree[2*MAXN] ,depth[2*MAXN] ,last[MAXN];
int n ,m ,idx = 0;

// sparse table
int table[MAXLOG][MAXN][2];
int logs[MAXN];

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

void computeLogs() {
  	for (int i = 2; i < MAXN; i++) {
		logs[i] = logs[i / 2] + 1;
  	}
}

void buildSparseTable(int n) {
	int curLen;
  	for (int i = 0; i <= logs[n]; i++) {
		curLen = 1 << i;
		for (int j = 0; j + curLen <= n; j++) {
	  		if (curLen == 1) {
				table[i][j][0] = depth[j];
				table[i][j][1] = j;
	  		} else {
				table[i][j][0] = min(table[i - 1][j][0], table[i - 1][j + (curLen / 2)][0]);
				table[i][j][1] = (table[i - 1][j][0] == table[i][j][0])?table[i - 1][j][1]:table[i - 1][j + (curLen / 2)][1];
	  		}
		}
  	}
}

int getMin(int l, int r) {
    r++;
  	int p = logs[r - l + 1];
  	int pLen = 1 << p;
  	int node_idx = (min(table[p][l][0], table[p][r - pLen + 1][0]) == table[p][l][0])?table[p][l][1]:table[p][r - pLen + 1][1];
  	return euler_tree[node_idx];
}

void rmq(){
    computeLogs();
    buildSparseTable(2*n-1);
}
void lca(int u ,int v){
    int a = getMin(min(last[u] ,last[v]) , max(last[u] ,last[v]));
    cout << a << "\n";
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
// 	// print()
// 	for(int i = 0 ;i < 2*n-1 ;i++) cout << euler_tree[i] << " ";
// 	cout << "\n";
// 	for(int i = 0 ;i < 2*n-1 ;i++) cout << depth[i] << " ";
// 	cout << "\n";
// 	for(int i = 0 ;i < n ;i++) cout <<i<<" -> "<< last[i] << "\n";
    int q;
    cin >> q;
    rmq();
    for(int i = 0; i < q ; i++){
        cin >> u >> v;
        lca(u ,v);
    }
	return 0;
}