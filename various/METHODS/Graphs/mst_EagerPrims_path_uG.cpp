// Prims Algorithm for Minimum Spanning Tree 
// for Sparse Graph
// for path only 

// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
#define int long long
#define INF LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;
vector<vector<pair<int ,int>>> adj(MAXN ,vector<pair<int ,int>>( 0 ));
vector<pair<int ,int>>min_e(MAXN);
vector<int> key(MAXN ,INF) ,par(MAXN ,-1);
bool visited[MAXN] = {0};
int n ,m ,total_weight = 0;

struct compare{
	constexpr bool operator()(
		pair<int ,int> const& a ,pair<int ,int> const& b)
		const noexcept {
			return a.second < b.second;
		}
};

void prim(int start){
	min_e[start] = {start ,0};
	priority_queue<pair<int ,int> ,vector<pair<int ,int>> ,greater<pair<int ,int>>> pq;
	pq.push(MP(0 ,start));
	key[start] = 0;
	int v ,u ,wt;
	pair<int ,int> vp;
	while(!pq.empty()){
		vp = pq.top();pq.pop();
		v = vp.S;
		visited[v] = 1;
		for(pair<int ,int> x : adj[v]){
			u = x.F;wt = x.S;
			if(!visited[u] && key[u] > wt){
				key[u] = wt;
				pq.push(MP(key[u] ,u));
				par[u] = v; 
			}
		} 
	}
	for(int i = 1; i <n ;i++) cout << par[i]<<"-"<<i<<"\n";
	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int u ,v ,w;
	cin >> n >> m;
	while(m--){
		cin >> v >> u >> w;
		u--;v--;
		adj[v].PB(MP(u ,w));
		adj[u].PB(MP(v ,w));
	}
	prim(0);

	return 0;
}
