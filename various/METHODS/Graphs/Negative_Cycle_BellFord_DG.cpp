// negative cycle in a directed grapf using bellman ford 

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
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
bool visited[MAXN] = {0};
int n ,m;
const int INF = LONG_LONG_MAX;
 
void solve(){
    vector<int> d(MAXN) ,p(MAXN ,-1);
    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(int v = 0 ;v < n ;v++){
            for(pair<int,int> u : adj[v]){
                if(d[v] + u.S < d[u.F]){
                    d[u.F] = d[v] + u.S;
                    p[u.F] = v;
                    x = u.F;
                }
            }
        }
    }
    if(x == -1){cout << "NO";return;}
    for(int i = 0; i < n ;++i) x = p[x];
    vector<int> cycle;
    cycle.reserve(MAXN+1);

    while(!visited[x]) x = p[x] ,visited[x] = 1; // for errors(IMP)
    for (int v = x;; v = p[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1)break;
    }
    reverse(ALL(cycle));
 
    cout << "YES\n";
    for (int v : cycle) cout << v+1 << ' ';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int u ,v ,w;
    cin>>n;
    cin>>m;
    while(m--) {
        cin>>u>>v>>w;
        adj[--u].push_back(MP(--v ,w));
    }
    solve();
    return 0;
}