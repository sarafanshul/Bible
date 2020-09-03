// Prims Algorithm for Minimum Spanning Tree 
// for Sparse Graph
// for path and total using std::set

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

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};
vector<vector<Edge>> adj(MAXN ,vector<Edge>(0));
vector<Edge> min_e(MAXN);
bool visited[MAXN] = {0};
int n ,m ,total_weight = 0;

void prim() {
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "NO Solution" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        visited[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v]) {
            if (!visited[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }
    cout << total_weight;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int u ,v ,w;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
	    Edge e1 ,e2;
		cin >> v >> u >> w;
		u--;v--;
		e1.w = w;e1.to = u;e2.w = w;e2.to = v;
		adj[v].PB(e1);
		adj[u].PB(e2);
	}
	prim();
	return 0;
}
