// https://cp-algorithms.com/graph/bellman_ford.html
// https://www.youtube.com/watch?v=lyw4FaxrwHg&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=19
// graphs with negative edge weights where dijkstra does not work

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
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;
bool u[MAXN] = {false};
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
vector<int> top_sort ,d(MAXN ,INT_MAX) ,p(MAXN ,-1) ,path;
int n ,m;
bool _cycle = 0;

void bellmanFord(int start){
    d[start] = 0;
    int x;
    for(int i = 0; i <= n ; i++){
        x = -1;
        for(int v = 0 ; v <= n ; v++){
            for(pair<int ,int> u :adj[v]){
                if(d[v] != INT_MAX){
                    if(d[u.F] > d[v] + u.S){
                        d[u.F] = max(INT_MIN ,d[v] + u.S);
                        p[u.F] = v;
                        x = u.F;
                    }
                }
            }
        }
    }
    if ( x == -1) cout << "NO NEGATIVE CYCLE FROM " << start <<"\n";
    else {
        _cycle = 1;
        int y = x;
        for(int i = 0; i <= n; ++i){
            y = p[y];
        }
        
        for(int cur = y ; ;cur = p[cur]){
            path.PB(cur);
            if(cur == y && path.size() > 1) break;
        }
        
        reverse(ALL(path));
        cout << "NEGATIVE CYCLE OF LEN : " << path.size()-1 <<"\n";
        for(size_t i = 0; i <path.size(); ++i){
            cout << path[i] << " ";
        }cout <<"\n";
    } 
}
void restore_path(int v , int t){
    if(d[t] == INT_MAX || _cycle) {cout << "NO PATH EXIST / CYCLE(s) EXIST\n";return;}
    path.clear();
    for(int cur = t ;cur != 1; cur = p[cur]){
        path.PB(cur);
    }
    reverse(ALL(path));
    cout << "Path from " << v << " to " << t << ": ";
    for (size_t i=0; i<path.size(); ++i)
        cout << path[i] << ' '; 
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int u ,v ,w;
    cin>>n;
    cin>>m;
    path.reserve(MAXN);
    while(m--) {
        cin>>u>>v>>w;
        adj[u].push_back(MP(v ,w)); // DAG
    }
    bellmanFord(0);
    restore_path(0 ,9);
    return 0;
}