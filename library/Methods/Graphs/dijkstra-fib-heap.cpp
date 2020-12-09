// https://cp-algorithms.com/graph/dijkstra_sparse.html

//https://www.youtube.com/watch?v=GazC3A4OQTE

vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
vector<int> d(MAXN ,INT_MAX) ,p(MAXN ,-1);
int n ,m;

void dijkstra(int s) {
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (pii edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    for(int i = 1; i <= n ;i++) cout << i << "->" << d[i] <<"\n";
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

//  dijkstra(1);
//  vector<int> p = restore_path(1 ,6);